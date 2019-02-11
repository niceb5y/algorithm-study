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
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (_) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
var axios_1 = __importDefault(require("axios"));
var chalk_1 = __importDefault(require("chalk"));
var cheerio_1 = __importDefault(require("cheerio"));
var figlet_1 = __importDefault(require("figlet"));
var fs_1 = __importDefault(require("fs"));
var ora_1 = __importDefault(require("ora"));
var path_1 = __importDefault(require("path"));
var commander_1 = __importDefault(require("commander"));
var readline_1 = __importDefault(require("readline"));
var util_1 = __importDefault(require("util"));
var SCRIPT_VERSION = "0.1.1";
commander_1.default
    .version(SCRIPT_VERSION, "-v, --version")
    .option("-l --lang <lang>", 'programming language ["cpp", "go"]', /^(cpp|go)$/i, "cpp")
    .parse(process.argv);
function ask(query) {
    return __awaiter(this, void 0, void 0, function () {
        var rl, result;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    rl = readline_1.default.createInterface({
                        input: process.stdin,
                        output: process.stdout
                    });
                    return [4 /*yield*/, util_1.default.promisify(function (question, callback) {
                            rl.question(question, callback.bind(null, null));
                        })(query)];
                case 1:
                    result = _a.sent();
                    rl.close();
                    return [2 /*return*/, result];
            }
        });
    });
}
function init() {
    return __awaiter(this, void 0, void 0, function () {
        return __generator(this, function (_a) {
            console.clear();
            console.log(chalk_1.default.blue(figlet_1.default.textSync("Util/New")));
            console.log();
            return [2 /*return*/];
        });
    });
}
function main() {
    return __awaiter(this, void 0, void 0, function () {
        var problemNum, _a, _b, projectPath, newDirNum, step1, step2, step3, step4, step5, res, body, $, htmlTitle, step6, sampleInput, sampleOutput, text, step7, text, step8, timezoneOffset, today, readme, problemTitle, step9, travisConf;
        return __generator(this, function (_c) {
            switch (_c.label) {
                case 0: return [4 /*yield*/, init()];
                case 1:
                    _c.sent();
                    _a = parseInt;
                    if (!(commander_1.default.args.length == 1)) return [3 /*break*/, 2];
                    _b = commander_1.default.args[0];
                    return [3 /*break*/, 4];
                case 2: return [4 /*yield*/, ask("어떤 문제를 푸시겠습니까?: ")];
                case 3:
                    _b = _c.sent();
                    _c.label = 4;
                case 4:
                    problemNum = _a.apply(void 0, [(_b).replace("https://www.acmicpc.net/problem/", "")]);
                    if (problemNum < 1000 || isNaN(problemNum) || !isFinite(problemNum)) {
                        ora_1.default("올바르지 않은 입력입니다.").fail();
                        process.exit(1);
                    }
                    console.log();
                    console.log(chalk_1.default.yellow("작업을 시작합니다."));
                    console.log();
                    projectPath = path_1.default.join(__dirname, "..");
                    newDirNum = 1;
                    while (fs_1.default.existsSync(path_1.default.join(projectPath, "" + newDirNum))) {
                        ++newDirNum;
                    }
                    step1 = ora_1.default("\uD504\uB85C\uC81D\uD2B8 \uB514\uB809\uD1A0\uB9AC \uC0DD\uC131").start();
                    fs_1.default.mkdirSync(path_1.default.join(projectPath, "" + newDirNum));
                    step1.succeed();
                    step2 = ora_1.default("\uD504\uB85C\uC81D\uD2B8 \uD14C\uC2A4\uD2B8 \uB514\uB809\uD1A0\uB9AC \uC0DD\uC131").start();
                    fs_1.default.mkdirSync(path_1.default.join(projectPath, newDirNum + "/test"));
                    step2.succeed();
                    step3 = ora_1.default("Makefile \uD30C\uC77C \uC0DD\uC131").start();
                    fs_1.default.copyFileSync(path_1.default.join(__dirname, "/templates/Makefile_" + commander_1.default.lang), path_1.default.join(projectPath, "" + newDirNum, "Makefile"));
                    step3.succeed();
                    step4 = ora_1.default("main." + commander_1.default.lang + " \uD30C\uC77C \uC0DD\uC131").start();
                    fs_1.default.copyFileSync(path_1.default.join(__dirname, "/templates/boilerplate_" + commander_1.default.lang), path_1.default.join(projectPath, "" + newDirNum, "main." + commander_1.default.lang));
                    step4.succeed();
                    step5 = ora_1.default("\uBB38\uC81C \uC815\uBCF4 \uB2E4\uC6B4\uB85C\uB4DC").start();
                    return [4 /*yield*/, axios_1.default.get("https://www.acmicpc.net/problem/" + problemNum)];
                case 5:
                    res = _c.sent();
                    body = res.data;
                    $ = cheerio_1.default.load(body);
                    htmlTitle = $("title").text();
                    step5.succeed(htmlTitle + " \uBB38\uC81C \uC815\uBCF4 \uB2E4\uC6B4\uB85C\uB4DC");
                    step6 = ora_1.default("\uD14C\uC2A4\uD2B8 \uCF00\uC774\uC2A4 \uC785\uB825 \uC0DD\uC131").start();
                    sampleInput = 1, sampleOutput = 1;
                    while ($("#sample-input-" + sampleInput).length > 0) {
                        text = $("#sample-input-" + sampleInput).text();
                        if (text === "") {
                            ++sampleInput;
                            continue;
                        }
                        if (!text.endsWith("\n"))
                            text += "\n";
                        fs_1.default.writeFileSync(path_1.default.join(projectPath, "" + newDirNum, "test/" + sampleInput + ".input"), text);
                        ++sampleInput;
                    }
                    step6.succeed();
                    step7 = ora_1.default("\uD14C\uC2A4\uD2B8 \uCF00\uC774\uC2A4 \uCD9C\uB825 \uC0DD\uC131").start();
                    while ($("#sample-output-" + sampleOutput).length > 0) {
                        text = $("#sample-output-" + sampleOutput).text();
                        if (!text.endsWith("\n"))
                            text += "\n";
                        fs_1.default.writeFileSync(path_1.default.join(projectPath, "" + newDirNum, "test/" + sampleOutput + ".answer"), text);
                        ++sampleOutput;
                    }
                    step7.succeed();
                    step8 = ora_1.default("README.md \uC218\uC815").start();
                    timezoneOffset = new Date().getTimezoneOffset() * 60000;
                    today = new Date(Date.now() - timezoneOffset)
                        .toISOString()
                        .substring(0, 10);
                    readme = fs_1.default.readFileSync(path_1.default.join(projectPath, "README.md")).toString();
                    problemTitle = htmlTitle.split(": ")[1];
                    readme = readme.replace("\n\n## 참고 링크", "\n- " + today + " " + problemTitle + " [\\[\uBB38\uC81C\\]](https://www.acmicpc.net/problem/" + problemNum + ") [\\[\uCF54\uB4DC\\]](https://github.com/niceb5y/algorithm-study/blob/niceb5y/" + newDirNum + "/main." + commander_1.default.lang + ")\n\n## \uCC38\uACE0 \uB9C1\uD06C");
                    fs_1.default.writeFileSync(path_1.default.join(projectPath, "README.md"), readme);
                    step8.succeed();
                    step9 = ora_1.default(".travis.yml \uC218\uC815").start();
                    travisConf = fs_1.default
                        .readFileSync(path_1.default.join(projectPath, ".travis.yml"))
                        .toString();
                    travisConf = travisConf.replace("\"cd " + (newDirNum - 1) + "\"", "\"cd " + newDirNum + "\"");
                    fs_1.default.writeFileSync(path_1.default.join(projectPath, ".travis.yml"), travisConf);
                    step9.succeed();
                    console.log();
                    console.log(chalk_1.default.green("\u2728 \uC791\uC5C5 \uC644\uB8CC \u2728"));
                    console.log();
                    console.log(chalk_1.default.blue("'cd " + newDirNum + "'(\uC73C)\uB85C " + problemTitle + "\uC758 \uD480\uC774\uB97C \uC2DC\uC791\uD558\uC138\uC694."));
                    console.log();
                    return [2 /*return*/];
            }
        });
    });
}
main();
