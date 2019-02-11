#!/usr/local/bin/node
"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const chalk_1 = __importDefault(require("chalk"));
const crypto_1 = __importDefault(require("crypto"));
const figlet_1 = __importDefault(require("figlet"));
const fs_1 = __importDefault(require("fs"));
const ora_1 = __importDefault(require("ora"));
const path_1 = __importDefault(require("path"));
const commander_1 = __importDefault(require("commander"));
const SCRIPT_VERSION = "0.1.1";
const SupportedLanguages = ["cpp", "go"];
commander_1.default.version(SCRIPT_VERSION, "-v, --version").parse(process.argv);
function getHash(path) {
    const file = fs_1.default.readFileSync(path);
    const sha1 = crypto_1.default.createHash("sha1");
    sha1.update(file);
    return sha1.digest("hex");
}
function init() {
    console.clear();
    console.log(chalk_1.default.blue(figlet_1.default.textSync("Util/Sync")));
    console.log();
}
function main() {
    init();
    console.log();
    console.log(chalk_1.default.yellow("작업을 시작합니다."));
    console.log();
    const projectPath = path_1.default.join(__dirname, "..");
    const makefilePath = SupportedLanguages.map(ext => path_1.default.join(projectPath, `util/templates/Makefile_${ext}`));
    const makefileHash = makefilePath.map(makefile => getHash(makefile));
    const step1 = ora_1.default("Makefile 동기화").start();
    let newDirNum = 1;
    while (fs_1.default.existsSync(path_1.default.join(projectPath, `${newDirNum}`))) {
        const projectMakefilePath = path_1.default.join(projectPath, `${newDirNum}/Makefile`);
        const projectMakefileExists = fs_1.default.existsSync(projectMakefilePath);
        const projectMakefileHash = projectMakefileExists
            ? getHash(projectMakefilePath)
            : "";
        const projectEntryExists = ext => fs_1.default.existsSync(path_1.default.join(projectPath, `${newDirNum}/main.${ext}`));
        if (!projectMakefileExists ||
            !makefileHash.some(hash => hash == projectMakefileHash)) {
            SupportedLanguages.forEach((ext, index) => {
                if (projectEntryExists(ext)) {
                    fs_1.default.copyFileSync(makefilePath[index], projectMakefilePath);
                }
            });
            step1.info(`${newDirNum}/Makefile 업데이트`);
        }
        ++newDirNum;
    }
    step1.succeed();
    console.log();
    console.log(chalk_1.default.green(`✨ 작업 완료 ✨`));
    console.log();
    console.log(chalk_1.default.blue(`모든 프로젝트 설정이 최신입니다.`));
    console.log();
}
main();
