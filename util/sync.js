"use strict";
/**
 * util/sync.js
 * Sync project configs
 * Copyright (c) 2019 Seungho Kim.
 */
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
    var makefilePath = path_1.default.join(__dirname, "templates/Makefile");
    var makefileHash = getHash(makefilePath);
    var step1 = ora_1.default("Makefile 동기화").start();
    var newDirNum = 1;
    while (fs_1.default.existsSync(path_1.default.join(projectPath, "" + newDirNum))) {
        var projectMakefilePath = path_1.default.join(projectPath, newDirNum + "/Makefile");
        var projectMakefileHash = getHash(projectMakefilePath);
        var projectMakefileExists = fs_1.default.existsSync(projectMakefilePath);
        if (!projectMakefileExists || makefileHash != projectMakefileHash) {
            fs_1.default.copyFileSync(makefilePath, projectMakefilePath);
            step1.info(newDirNum + "/Makefile \uC5C5\uB370\uC774\uD2B8");
        }
        ++newDirNum;
    }
    step1.succeed();
    console.log();
    console.log(chalk_1.default.green("\u2728 \uC791\uC5C5 \uC644\uB8CC \u2728"));
    console.log();
    console.log(chalk_1.default.blue("\uBAA8\uB4E0 \uD504\uB85C\uC81D\uD2B8 \uC124\uC815\uC774 \uCD5C\uC2E0\uC785\uB2C8\uB2E4."));
    console.log();
}
main();
