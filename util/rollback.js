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
const chalk_1 = __importDefault(require("chalk"));
const figlet_1 = __importDefault(require("figlet"));
const fs_1 = __importDefault(require("fs"));
const ora_1 = __importDefault(require("ora"));
const path_1 = __importDefault(require("path"));
const commander_1 = __importDefault(require("commander"));
const readline_1 = __importDefault(require("readline"));
const util_1 = __importDefault(require("util"));
const SCRIPT_VERSION = "0.1.0";
commander_1.default
    .version(SCRIPT_VERSION, "-v, --version")
    .option("-y, --yes", "automatic yes to prompts")
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
        console.log(chalk_1.default.blue(figlet_1.default.textSync("Util/Rollback")));
        console.log();
    });
}
function main() {
    return __awaiter(this, void 0, void 0, function* () {
        yield init();
        const operationGranted = commander_1.default.yes || (yield ask("롤백을 시작할까요? [y/N]: ")) == "y";
        if (!operationGranted) {
            ora_1.default("작업을 종료합니다.").fail();
            process.exit(1);
        }
        console.log();
        console.log(chalk_1.default.yellow("작업을 시작합니다."));
        console.log();
        const projectPath = path_1.default.join(__dirname, "..");
        let latestDirNum = 1;
        while (fs_1.default.existsSync(path_1.default.join(projectPath, `${latestDirNum}`))) {
            ++latestDirNum;
        }
        --latestDirNum;
        const step1 = ora_1.default(`프로젝트 테스트 디렉토리 제거`).start();
        fs_1.default.readdirSync(path_1.default.join(projectPath, `${latestDirNum}/test`)).forEach(file => fs_1.default.unlinkSync(path_1.default.join(projectPath, `${latestDirNum}/test/${file}`)));
        fs_1.default.rmdirSync(path_1.default.join(projectPath, `${latestDirNum}/test`));
        step1.succeed();
        const step2 = ora_1.default(`프로젝트 디렉토리 제거`).start();
        fs_1.default.readdirSync(path_1.default.join(projectPath, `${latestDirNum}`)).forEach(file => fs_1.default.unlinkSync(path_1.default.join(projectPath, `${latestDirNum}/${file}`)));
        fs_1.default.rmdirSync(path_1.default.join(projectPath, `${latestDirNum}`));
        step2.succeed();
        const step3 = ora_1.default(`README.md 수정`).start();
        let readme = fs_1.default.readFileSync(path_1.default.join(projectPath, "README.md")).toString();
        readme = readme
            .split("\n")
            .filter(line => !line.includes(`https://github.com/niceb5y/algorithm-study/blob/niceb5y/${latestDirNum}`))
            .join("\n");
        fs_1.default.writeFileSync(path_1.default.join(projectPath, "README.md"), readme);
        step3.succeed();
        const step4 = ora_1.default(`.travis.yml 수정`).start();
        let travisConf = fs_1.default
            .readFileSync(path_1.default.join(projectPath, ".travis.yml"))
            .toString();
        travisConf = travisConf.replace(`"cd ${latestDirNum}"`, `"cd ${latestDirNum - 1}"`);
        fs_1.default.writeFileSync(path_1.default.join(projectPath, ".travis.yml"), travisConf);
        step4.succeed();
        console.log();
        console.log(chalk_1.default.green(`✨ 작업 완료 ✨`));
        console.log();
    });
}
main();
