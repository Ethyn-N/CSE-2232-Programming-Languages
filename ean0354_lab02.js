// Ethyn Nguyen
// 1001930354
// March 7, 2023

// Question - 1
// Create an array named inputtable with numbers between 1 and 10.

// Creating a const array inputtable with numbers between 1 and 10 in increasing order.
const inputtable = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

console.log("Question - 1\nCreate an array named inputtable with numbers between 1 and 10.\n");
console.log(inputtable);
console.log("\n");

// Question - 2a
// Set of multiples of 5 between 1 and 51.

// Using map() to create a new array fiveTable by multiplying by 5 for every array element in inputtable.
const fiveTable = inputtable.map(element => element * 5);

console.log("Question - 2a\nSet of multiples of 5 between 1 and 51.\n");
console.log(fiveTable);
console.log("\n");

// Question - 2b
// Set of multiples of 13 between 1 and 131.

// Using map() to create a new array thirteenTable by multiplying by 13 for every array element in inputtable.
const thirteenTable = inputtable.map(element => element * 13);

console.log("Question - 2b\nSet of multiples of 13 between 1 and 131.\n");
console.log(thirteenTable);
console.log("\n");

// Question - 2c
// Set of squares of the numbers in inputtable.

// Using map() to create a new array thirteenTable by squaring every array element in inputtable.
const squaresTable = inputtable.map(element => Math.pow(element, 2));

console.log("Question - 2c\nSet of squares of the numbers in inputtable.\n");
console.log(squaresTable);
console.log("\n");

// Question - 3
// Get (and then print) the odd multiples of 5 between 1 and 100.

// Creating a const array numSet with numbers between 1 and 100 in increasing order.
const numSet = Array.from(Array(100).keys()).map(element => element + 1);

// filter() is used to remove any array element that is not an odd number
// and keeps only multiples of 5.
const oddFiveTable = numSet.filter(element => element % 2 != 0 && element % 5 == 0);

console.log("Question - 3\nGet (and then print) the odd multiples of 5 between 1 and 100.\n");
console.log(oddFiveTable);
console.log("\n");

// Question - 4
// Get the sum of even multiples of 7 between 1 and 100.

// filter() is used to remove any array element that is not an even number and keeps only multiples of 7.
// reduce() is used to sum all the remaining even numbers into one result.
const sumSevenEvenMultiples = numSet.filter(element => element % 2 == 0 && element % 7 == 0).reduce((result, element) => result + element);

console.log("Question - 4\nGet the sum of even multiples of 7 between 1 and 100.\n");
console.log(sumSevenEvenMultiples);
console.log("\n");

// Question - 5
// Use currying to rewrite the function below:
/*
function cylinder_volume(r, h) { 
    var volume = 3.14 * r * r * h; 
    return volume; 
} 
*/

// Currying the function so that cylinder_volume only takes 1 parameter at a time.
const cylinder_volume = r => h => 3.14 * r * r * h;
    
// Question - 5a
// Use r = 5 and h = 10 to call your curried function.

console.log("Question - 5a\nUse r = 5 and h = 10 to call your curried function.\n");
console.log(cylinder_volume(5)(10));
console.log("\n");

// Question - 5b
// Reuse the function from part 'a' but use h = 17.

console.log("Question - 5b\nReuse the function from part 'a' but use h = 17.\n");
console.log(cylinder_volume(5)(17));
console.log("\n");

// Question - 5b
// Reuse the function from part 'a' but use h = 11.

console.log("Question - 5c\nReuse the function from part 'a' but use h = 11.\n");
console.log(cylinder_volume(5)(11));
console.log("\n");

// Question - 6
// Use the following code to take advantage of closures to wrap content with
// HTML tags, specifically show an HTML table consisting of a table row that has at least
// one table cell/element. You can use the console to output your results.

console.log("Question - 6\nUse the following code to take advantage of closures to wrap content with\n" +
            "HTML tags, specifically show an HTML table consisting of a table row that has at least\n" +
            "one table cell/element. You can use the console to output your results.\n");

makeTag = function(beginTag, endTag) {
    return function(textcontent) { 
        return beginTag + textcontent + endTag; 
    } 
}

// Using makeTag to make tags for the table, table data, table row, and table header.
// Using the concept of closure, the function for textcontent is returned.
const tableTag = makeTag("<table>\n", "</table>\n");
const tableHeaderTag = makeTag("<th>", "</th>\n");
const tableRowTag = makeTag("<tr>\n", "</tr>\n");
const tableDataTag = makeTag("<td>", "</td>\n");


// Combining table header tags for the content of the header.
const header1 = tableHeaderTag("Firstname");
const header2 = tableHeaderTag("Lastname");
const header3 = tableHeaderTag("Age");
const headerContent = header1 + header2 + header3;

// Combining table data tags for the content of the first cell.
const firstName1 = tableDataTag("Ethyn");
const lastName1 = tableDataTag("Nguyen");
const age1 = tableDataTag(20);
const cellContent1 = firstName1 + lastName1 + age1;

// Combining table row tags for the content of the rows.
const row1 = tableRowTag(headerContent);
const row2 = tableRowTag(cellContent1);
const rowContent = row1 + row2;

// Final table tag for combining all the data into one html table.
const table = tableTag(rowContent);
console.log(table);

console.log("\n");

// Question - 8
// Do the ‘generic’ version of questions 3 and 4, meaning the target multiple must not be hard coded.

console.log("Question - 8\nDo the 'generic' version of questions 3 and 4, meaning the target multiple must not be hard coded.");
console.log("\n");

// Generic function to find odd or even multiples in numSet.
function genericMultiples(multiple, odd) {
    // multiple is the generic multiple.
    // Odd is either '1' for odd multiples or '0' for even multiples.
    
    // filter() is used to remove any elements that are not a multiple
    // and are either odd or even depending on the odd paremeter.
    return numSet.filter(element => element % multiple == 0 && element % 2 == odd); 
}

// Generic function to get the sum of multiples.
function genericSum(multiple, odd) {
    // multiple is the generic multiple.
    // Odd is either '1' for odd multiples or '0' for even multiples.
    
    // genericMultiples creates an array of multiples that are 
    // either odd or even depending on the odd paremeter.
    // If determines if the array is empty so that it doesn't reduce() an empty array.
    // reduce() is used to to sum all the remaining numbers into one result.
    if (genericMultiples(multiple, odd) != 0)
        return genericMultiples(multiple, odd).reduce((result, element) => result + element);
    else
        return 0;
}

// Example Uses

console.log("Example of generic multiples with odd multiples of 11\n")
console.log(genericMultiples(11, 1));
console.log("\n");

console.log("Example of generic sum with even multiples of 3\n")
console.log(genericSum(3, 0));
console.log("\n");
