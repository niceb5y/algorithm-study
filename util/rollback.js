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
var chalk_1 = __importDefault(require("chalk"));
var figlet_1 = __importDefault(require("figlet"));
var fs_1 = __importDefault(require("fs"));
var ora_1 = __importDefault(require("ora"));
var path_1 = __importDefault(require("path"));
var commander_1 = __importDefault(require("commander"));
var readline_1 = __importDefault(require("readline"));
var util_1 = __importDefault(require("util"));
var SCRIPT_VERSION = "0.1.0";
commander_1.default
    .version(SCRIPT_VERSION, "-v, --version")
    .option("-y, --yes", "automatic yes to prompts")
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
            console.log(chalk_1.default.blue(figlet_1.default.textSync("Util/Rollback")));
            console.log();
            return [2 /*return*/];
        });
    });
}
function main() {
    return __awaiter(this, void 0, void 0, function () {
        var operationGranted, _a, projectPath, latestDirNum, step1, step2, step3, readme, step4, travisConf;
        return __generator(this, function (_b) {
            switch (_b.label) {
                case 0: return [4 /*yield*/, init()];
                case 1:
                    _b.sent();
                    _a = commander_1.default.yes;
                    if (_a) return [3 /*break*/, 3];
                    return [4 /*yield*/, ask("롤백을 시작할까요? [y/N]: ")];
                case 2:
                    _a = (_b.sent()) == "y";
                    _b.label = 3;
                case 3:
                    operationGranted = _a;
                    if (!operationGranted) {
                        ora_1.default("작업을 종료합니다.").fail();
                        process.exit(1);
                    }
                    console.log();
                    console.log(chalk_1.default.yellow("작업을 시작합니다."));
                    console.log();
                    projectPath = path_1.default.join(__dirname, "..");
                    latestDirNum = 1;
                    while (fs_1.default.existsSync(path_1.default.join(projectPath, "" + latestDirNum))) {
                        ++latestDirNum;
                    }
                    --latestDirNum;
                    step1 = ora_1.default("\uD504\uB85C\uC81D\uD2B8 \uD14C\uC2A4\uD2B8 \uB514\uB809\uD1A0\uB9AC \uC81C\uAC70").start();
                    fs_1.default.readdirSync(path_1.default.join(projectPath, latestDirNum + "/test")).forEach(function (file) {
                        return fs_1.default.unlinkSync(path_1.default.join(projectPath, latestDirNum + "/test/" + file));
                    });
                    fs_1.default.rmdirSync(path_1.default.join(projectPath, latestDirNum + "/test"));
                    step1.succeed();
                    step2 = ora_1.default("\uD504\uB85C\uC81D\uD2B8 \uB514\uB809\uD1A0\uB9AC \uC81C\uAC70").start();
                    fs_1.default.readdirSync(path_1.default.join(projectPath, "" + latestDirNum)).forEach(function (file) {
                        return fs_1.default.unlinkSync(path_1.default.join(projectPath, latestDirNum + "/" + file));
                    });
                    fs_1.default.rmdirSync(path_1.default.join(projectPath, "" + latestDirNum));
                    step2.succeed();
                    step3 = ora_1.default("README.md \uC218\uC815").start();
                    readme = fs_1.default.readFileSync(path_1.default.join(projectPath, "README.md")).toString();
                    readme = readme
                        .split("\n")
                        .filter(function (line) {
                        return !line.includes("https://github.com/niceb5y/algorithm-study/blob/niceb5y/" + latestDirNum);
                    })
                        .join("\n");
                    fs_1.default.writeFileSync(path_1.default.join(projectPath, "README.md"), readme);
                    step3.succeed();
                    step4 = ora_1.default(".travis.yml \uC218\uC815").start();
                    travisConf = fs_1.default
                        .readFileSync(path_1.default.join(projectPath, ".travis.yml"))
                        .toString();
                    travisConf = travisConf.replace("\"cd " + latestDirNum + "\"", "\"cd " + (latestDirNum - 1) + "\"");
                    fs_1.default.writeFileSync(path_1.default.join(projectPath, ".travis.yml"), travisConf);
                    step4.succeed();
                    console.log();
                    console.log(chalk_1.default.green("\u2728 \uC791\uC5C5 \uC644\uB8CC \u2728"));
                    console.log();
                    return [2 /*return*/];
            }
        });
    });
}
main();
