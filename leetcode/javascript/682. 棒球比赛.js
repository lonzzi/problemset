/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function (ops) {
    var array = [];
    for (var i = 0; i < ops.length; i++) {
        if (ops[i][0] == '+') {
            array.push(array[array.length - 1] + array[array.length - 2]);
        } else if (ops[i][0] == 'D') {
            array.push(array[array.length - 1] * 2);
        } else if (ops[i][0] == 'C') {
            array.pop();
        } else {
            array.push(eval(ops[i]));
        }
    }
    var ans = 0;
    for (i of array) {
        ans += i;
    }
    return ans;
};

console.log(calPoints(["5", "-2", "4", "C", "D", "9", "+", "+"]))