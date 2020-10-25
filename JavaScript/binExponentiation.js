/*
Implement binExp(num, pow), 
        which calculates num raised to the power pow (i.e. num^pow).
*/


/*
    Input: x = 2.00000, n = 10
    Output: 1024.00000

    Input: x = 2.00000, n = -2
    Output: 0.25000
*/

var binExp = function (num, pow) {

    let res = 1;

    let flag = 0;

    if (pow < 0) {
        pow = -1 * pow;
        flag++;
    }

    while (pow > 0) {
        if (pow % 2 == 0) {
            num = num * num;
            pow = pow / 2;
        }
        else {
            res= res * num;
            pow = pow - 1;
        }
    }

    if (flag == 1)
        return 1 / res;
    else
        return res;
}

console.log(binExp(2,10)); 

console.log(binExp(2, -2));

/*
   Contributed by
      
      Pavan Kalyan Konudula

      SASTRA Deemed University

*/