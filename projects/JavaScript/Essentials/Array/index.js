// index.js
var B = [2,4,6,8,10];

var isDevServer = true;
// running program from cli? 1 = true or 0 = false
var cli = process.argv[2];
// console.log(cli);

if(cli == true)
{
    isDevServer = false;
    // console.log(isDevServer);
}

for(var i = 0; i < B.length; i++)
{
    // writes HTML expressions or JS code into browser console
    // mainly used for debugging
    console.log(B[i] + " ");

    if(isDevServer == true)
    {
        // WARNNG: Must have webpack development server running
        // writes HTML expressions or JS code to HTML document
        // used for testing. If used after HTML doc is fully
        // loaded it will delete all existing HTML
        document.write(B[i] + " ");
    }
}