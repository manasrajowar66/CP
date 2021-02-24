process.stdin.resume();
process.stdin.setEncoding("utf-8");

let standardInputString = "";
let currentLine = 0;

const readline = () => standardInputString[currentLine++];

process.stdin.on("data", (rawdata) => {
  standardInputString += rawdata;
});

process.stdin.on("end", (_) => {
  standardInputString = standardInputString
    .trim()
    .split("\n")
    .map((line) => line.trim());
  main();
});

const allCount = (target, strings, memo = {}) => {
  if (target in memo) return memo[target];
  if (target === "") return [[]];
  const res = [];
  for (let str of strings) {
    if (target.indexOf(str) === 0) {
      const suffix = target.slice(str.length);
      let numberOfWays = allCount(suffix, strings);
      numberOfWays = numberOfWays.map((way) => [str, ...way]);
      res.push(...numberOfWays);
    }
  }
  memo[target] = res;
  return res;
};

const main = () => {
  let t = parseInt(readline());
  while (t--) {
    const target = readline();
    let strings = readline();
    strings = strings.split(" ").map((str) => str);
    const res = allCount(target, strings);
    console.log(res);
  }
};
