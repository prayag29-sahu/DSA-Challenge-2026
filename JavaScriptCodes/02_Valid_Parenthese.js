function valid_parentese(s) {
    let stack = [];
    let match = {
        ')': '(',
        '}': '{',
        ']': '['
    };

    for (const c of s) {
        if (!(c in match)) {
            stack.push(c);
        } else {
            if (!stack.length || stack[stack.length - 1] !== match[c]) return false;
            
            stack.pop();
        }
    }
    return !stack.length;

}

console.log(valid_parentese("()"));