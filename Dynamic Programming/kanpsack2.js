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

const knapsack = (arr, W, ind, memo = {}) => {
  const key = `${W},${ind}`;
  if (key in memo) return memo[key];
  if (W == 0 || arr.length == ind) return 0;
  let res1 = -Infinity;
  let res2 = -Infinity;
  if (W - arr[ind].w >= 0)
    res1 = arr[ind].v + knapsack(arr, W - arr[ind].w, ind + 1);
  res2 = knapsack(arr, W, ind + 1);
  return (memo[key] = Math.max(res1, res2));
};

const main = () => {
  let [n, W] = readline()
    .split(" ")
    .map((key) => parseInt(key));

  const arr = [];
  for (let i = 0; i < n; i++) {
    const [w, v] = readline()
      .split(" ")
      .map((key) => parseInt(key));
    arr.push({ w, v });
  }
  console.log(knapsack(arr, W, 0));
};
