#!/usr/local/bin/node
"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : new P(function (resolve) { resolve(result.value); }).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const axios_1 = __importDefault(require("axios"));
const chalk_1 = __importDefault(require("chalk"));
const cheerio_1 = __importDefault(require("cheerio"));
const figlet_1 = __importDefault(require("figlet"));
const fs_1 = __importDefault(require("fs"));
const ora_1 = __importDefault(require("ora"));
const path_1 = __importDefault(require("path"));
const commander_1 = __importDefault(require("commander"));
const readline_1 = __importDefault(require("readline"));
const util_1 = __importDefault(require("util"));
const SCRIPT_VERSION = "0.1.1";
commander_1.default
    .version(SCRIPT_VERSION, "-v, --version")
    .option("-l --lang <lang>", 'programming language ["cpp", "go"]', /^(cpp|go)$/i, "cpp")
    .parse(process.argv);
function ask(query) {
    return __awaiter(this, void 0, void 0, function* () {
        const rl = readline_1.default.createInterface({
            input: process.stdin,
            output: process.stdout
        });
        const result = yield util_1.default.promisify((question, callback) => {
            rl.question(question, callback.bind(null, null));
        })(query);
        rl.close();
        return result;
    });
}
function init() {
    return __awaiter(this, void 0, void 0, function* () {
        console.clear();
        console.log(chalk_1.default.blue(figlet_1.default.textSync("Util/New")));
        console.log();
    });
}
function main() {
    return __awaiter(this, void 0, void 0, function* () {
        yield init();
        const problemNum = parseInt((commander_1.default.args.length == 1
            ? commander_1.default.args[0]
            : yield ask("어떤 문제를 푸시겠습니까?: ")).replace("https://www.acmicpc.net/problem/", ""));
        if (problemNum < 1000 || isNaN(problemNum) || !isFinite(problemNum)) {
            ora_1.default("올바르지 않은 입력입니다.").fail();
            process.exit(1);
        }
        console.log();
        console.log(chalk_1.default.yellow("작업을 시작합니다."));
        console.log();
        const projectPath = path_1.default.join(__dirname, "..");
        let newDirNum = 1;
        while (fs_1.default.existsSync(path_1.default.join(projectPath, `${newDirNum}`))) {
            ++newDirNum;
        }
        const step1 = ora_1.default(`프로젝트 디렉토리 생성`).start();
        fs_1.default.mkdirSync(path_1.default.join(projectPath, `${newDirNum}`));
        step1.succeed();
        const step2 = ora_1.default(`프로젝트 테스트 디렉토리 생성`).start();
        fs_1.default.mkdirSync(path_1.default.join(projectPath, `${newDirNum}/test`));
        step2.succeed();
        const step3 = ora_1.default(`Makefile 파일 생성`).start();
        fs_1.default.copyFileSync(path_1.default.join(__dirname, `/templates/Makefile_${commander_1.default.lang}`), path_1.default.join(projectPath, `${newDirNum}`, "Makefile"));
        step3.succeed();
        const step4 = ora_1.default(`main.${commander_1.default.lang} 파일 생성`).start();
        fs_1.default.copyFileSync(path_1.default.join(__dirname, `/templates/boilerplate_${commander_1.default.lang}`), path_1.default.join(projectPath, `${newDirNum}`, `main.${commander_1.default.lang}`));
        step4.succeed();
        const step5 = ora_1.default(`문제 정보 다운로드`).start();
        const res = yield axios_1.default.get(`https://www.acmicpc.net/problem/${problemNum}`);
        const body = res.data;
        const $ = cheerio_1.default.load(body);
        const htmlTitle = $("title").text();
        step5.succeed(`${htmlTitle} 문제 정보 다운로드`);
        const step6 = ora_1.default(`테스트 케이스 입력 생성`).start();
        let sampleInput = 1, sampleOutput = 1;
        while ($(`#sample-input-${sampleInput}`).length > 0) {
            let text = $(`#sample-input-${sampleInput}`).text();
            if (text === "") {
                ++sampleInput;
                continue;
            }
            if (!text.endsWith("\n"))
                text += "\n";
            fs_1.default.writeFileSync(path_1.default.join(projectPath, `${newDirNum}`, `test/${sampleInput}.input`), text);
            ++sampleInput;
        }
        step6.succeed();
        const step7 = ora_1.default(`테스트 케이스 출력 생성`).start();
        while ($(`#sample-output-${sampleOutput}`).length > 0) {
            let text = $(`#sample-output-${sampleOutput}`).text();
            if (!text.endsWith("\n"))
                text += "\n";
            fs_1.default.writeFileSync(path_1.default.join(projectPath, `${newDirNum}`, `test/${sampleOutput}.answer`), text);
            ++sampleOutput;
        }
        step7.succeed();
        const step8 = ora_1.default(`README.md 수정`).start();
        const timezoneOffset = new Date().getTimezoneOffset() * 60000;
        const today = new Date(Date.now() - timezoneOffset)
            .toISOString()
            .substring(0, 10);
        let readme = fs_1.default.readFileSync(path_1.default.join(projectPath, "README.md")).toString();
        const problemTitle = htmlTitle.split(": ")[1];
        readme = readme.replace("\n\n## 참고 링크", `\n- ${today} ${problemTitle} [\\[문제\\]](https://www.acmicpc.net/problem/${problemNum}) [\\[코드\\]](https://github.com/niceb5y/algorithm-study/blob/niceb5y/${newDirNum}/main.${commander_1.default.lang})\n\n## 참고 링크`);
        fs_1.default.writeFileSync(path_1.default.join(projectPath, "README.md"), readme);
        step8.succeed();
        const step9 = ora_1.default(`.travis.yml 수정`).start();
        let travisConf = fs_1.default
            .readFileSync(path_1.default.join(projectPath, ".travis.yml"))
            .toString();
        travisConf = travisConf.replace(`"cd ${newDirNum - 1}"`, `"cd ${newDirNum}"`);
        fs_1.default.writeFileSync(path_1.default.join(projectPath, ".travis.yml"), travisConf);
        step9.succeed();
        console.log();
        console.log(chalk_1.default.green(`✨ 작업 완료 ✨`));
        console.log();
        console.log(chalk_1.default.blue(`'cd ${newDirNum}'(으)로 ${problemTitle}의 풀이를 시작하세요.`));
        console.log();
    });
}
main();
