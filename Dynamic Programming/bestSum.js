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

const bestSum = (sum, numbers, memo = {}) => {
  if (sum in memo) return memo[sum];
  if (sum === 0) return [];
  if (sum < 0) return null;

  let shortCombi = null;
  for (let num of numbers) {
    const remainder = sum - num;
    const remainderCombi = bestSum(remainder, numbers, memo);
    if (remainderCombi !== null) {
      const combi = [...remainderCombi, num];
      if (shortCombi === null || shortCombi.length > combi.length) {
        shortCombi = combi;
      }
    }
  }
  memo[sum] = shortCombi;
  return memo[sum];
};

const main = () => {
  let t = parseInt(readline());
  while (t--) {
    const s = readline();
    const nums = s.split(" ").map((st) => parseInt(st));
    const number = readline();
    const numbers = number.split(" ").map((num) => parseInt(num));
    const res = bestSum(nums[1], numbers);
    console.log(...res);
  }
};
