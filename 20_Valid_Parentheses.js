/**
 * @param {string} s
 * @return {boolean}
 */
 var isValid = function(s) {
    let myStack = [];
    let myMap = {'(':')', '[':']', '{':'}'};
    
    for(let i = 0; i < s.length; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            myStack.push(s[i]);
        }
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            let test = myStack.pop();
            if(myMap[test] != s[i])
            {
                return false;
            }
        }
    }

    if(myStack.length == 0)
    {
        return true;
    }
    else if(myStack.length != 0)
    {
        return false;
    }
};

// let ss = "(((((()))";
// console.log(isValid(ss));