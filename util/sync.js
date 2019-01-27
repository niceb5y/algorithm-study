#!/usr/local/bin/node
"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
var chalk_1 = __importDefault(require("chalk"));
var crypto_1 = __importDefault(require("crypto"));
var figlet_1 = __importDefault(require("figlet"));
var fs_1 = __importDefault(require("fs"));
var ora_1 = __importDefault(require("ora"));
var path_1 = __importDefault(require("path"));
var commander_1 = __importDefault(require("commander"));
var SCRIPT_VERSION = "0.1.0";
var SupportedLanguages = ["cpp", "go"];
commander_1.default.version(SCRIPT_VERSION, "-v, --version").parse(process.argv);
function getHash(path) {
    var file = fs_1.default.readFileSync(path);
    var sha1 = crypto_1.default.createHash("sha1");
    sha1.update(file);
    return sha1.digest("hex");
}
function init() {
    console.clear();
    console.log(chalk_1.default.blue(figlet_1.default.textSync("Util/Migrate")));
    console.log();
}
function main() {
    init();
    console.log();
    console.log(chalk_1.default.yellow("작업을 시작합니다."));
    console.log();
    var projectPath = path_1.default.join(__dirname, "..");
    var makefilePath = SupportedLanguages.map(function (ext) {
        return path_1.default.join(projectPath, "util/templates/Makefile_" + ext);
    });
    var makefileHash = makefilePath.map(function (makefile) { return getHash(makefile); });
    var step1 = ora_1.default("Makefile 동기화").start();
    var newDirNum = 1;
    var _loop_1 = function () {
        var projectMakefilePath = path_1.default.join(projectPath, newDirNum + "/Makefile");
        var projectMakefileExists = fs_1.default.existsSync(projectMakefilePath);
        var projectMakefileHash = projectMakefileExists
            ? getHash(projectMakefilePath)
            : "";
        var projectEntryExists = function (ext) {
            return fs_1.default.existsSync(path_1.default.join(projectPath, newDirNum + "/main." + ext));
        };
        if (!projectMakefileExists ||
            !makefileHash.some(function (hash) { return hash == projectMakefileHash; })) {
            SupportedLanguages.forEach(function (ext, index) {
                if (projectEntryExists(ext)) {
                    fs_1.default.copyFileSync(makefilePath[index], projectMakefilePath);
                }
            });
            step1.info(newDirNum + "/Makefile \uC5C5\uB370\uC774\uD2B8");
        }
        ++newDirNum;
    };
    while (fs_1.default.existsSync(path_1.default.join(projectPath, "" + newDirNum))) {
        _loop_1();
    }
    step1.succeed();
    console.log();
    console.log(chalk_1.default.green("\u2728 \uC791\uC5C5 \uC644\uB8CC \u2728"));
    console.log();
    console.log(chalk_1.default.blue("\uBAA8\uB4E0 \uD504\uB85C\uC81D\uD2B8 \uC124\uC815\uC774 \uCD5C\uC2E0\uC785\uB2C8\uB2E4."));
    console.log();
}
main();
