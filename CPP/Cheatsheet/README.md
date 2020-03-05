# C++ Cheatsheet

## Recursion

~~~cpp
int fact(int n) {
    if (n <= 1) { // base case
        return 1;
    }
    else { // recursive call
        return n*fact(n-1);
    }
}
~~~

## Array (Vector)

~~~cpp
vector<int> v{10,20,30,40,50};

for(int i=0; i < v.size(); i++) {
    cout << v[i] << " ";
}

// Insert 15 at end of vector
v.push_back(15);
int n = v.size();
cout << "Last element is: " << v[n-1];

// removes last element
v.pop_back();

for(int i=0; i < v.size(); i++) {
    cout << v[i] << " ";
}

// inserts 5 at beginning
v.insert(v.begin(), 5);

cout << "\nThe first element is: " << v[0];

// removes first element
v.erase(v.begin());

cout << "\nThe first element is: " << v[0];

// inserts 60 at the end
v.emplace_back(60);
n = v.size();
cout << "Last element is: " << v[n-1];

// erases the vector 
v.clear(); 
cout << "\nVector size after erase(): " << v.size();
~~~

## Strings

~~~cpp
// finding length of a string
string str = "GeeksforGeeks";

// 1. size of string object using size() method
cout << str.size() << endl;

// 2. size of string object using length method
cout << str.length() << endl;

// 3. size using old style, strlen
cout << strlen(str.c_str()) << endl;

// 4. size of string object using while loop, while "NOT NULL"
int i = 0;
while(str[i]) {
    i++;
}
cout << i << endl;

// changing case of a string to uppercase
string su = "James Guzman";

// using transform() function and ::toupper in STL
// first1, last1, result, operation
transform(su.begin(), su.end(), su.begin(), ::toupper);
cout << su << endl;

// changing case of string to lowercase
string s1 = "James Guzman";

// using transform() function and ::tolower in STL
transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
cout << s1 << end;

// counting vowels in a string
// 1. Iterative, Time Complexity: O(n), Space Complexity: O(1)
bool isVowel(char ch) {
    ch = toupper(ch);
    return (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
}

int countVowels(string str) {
    int count = 0;
    for(int i = 0; i < str.length(); i++) {
        if(isVowel(str[i])) {
            ++count;
        }
    }
    return count;
}

string str1 = "abc de";

cout << countVowels(str) << endl;

// 2. Recursive, Time Complexity: O(n), Space Complexity: O(n)
int countVowels2(string str, int n) {
    if (n == 1) {
        return isVowel(str[n-1]);
    }
    return countVowels2(str, n-1) + isVowel(str[n-1]);
}

cout << countVowels(str1, str1.length()) << endl;

// Counting words in a string
// Time Complexity: O(n)
// Space Complexity: O(1)
// OUT indicates that a separator is seen
#define OUT 0
// IN indicates a word character is seen
# define IN 1
unsigned countWords(char *str) {
    int state = OUT;
    unsigned wc = 0;

    // Scan all characters one by one
    while(*str) {
        // If next character is separator, set state as OUT
        if(*str == ' ' || *str == '\n' || *str == '\t') {
            state = OUT;
        }
        // If next character is not a word separator and state is OUT, then set the state as IN and increment word count
        else if(state == OUT) {
            state = IN;
            ++wc;
        }

        // Move to next character
        ++str;
    }
    return wc;
}

char str[] = "One two     three\n four\tfive ";
cout<<"No of words : "<<countWords(str);

// validating a string
bool isValid(string str) {
    int k = 0;
    string operands[5] = "";
    char operators[4];
    long ans = 0;
    for(int i = 0; i < str.length(); i++) {
        // If it is an integer, then add it to another string array
        if(str[i] != '+' && str[i] != '=' && str[i] != '-') {
            operands[k] += str[i];
        }
        else {
            operators[k] = str[i];

            // Evaluation of 1st operator
            if(k == 1) {
                if(operators[k-1] == '+') {
                    ans += stol(operands[k-1]) + stol(operands[k]);
                }
                if(operators[k-1] == '-') {
                    ans += stol(operands[k-1]) + stol(operands[k])
                }
            }

            // Evaluation of next operator
            if(k > 1 && str[i] != '=') {
                if(operators[k-1] == '+') {
                    ans += stol(operands[k]);
                }
                if(operators[k-1] == '-') {
                    ans -= stol(operands[k]);
                }
            }
            k++;
        }
        // If the LHS result is equal to RHS
        int n = operands.length()-1;
        if(ans == stol(operands[n]) {
            return true;
        })
        else {
            return false;
        }
    }
}

string eqn = "2+5+3+1=11";
if(isValid(eqn)) {
    cout << "Valid";
}
else {
    cout << "Invalid";
}

// reversing a string
// 1. Write your own reverse function by swapping characters
void reverseStr(string &str) {
    int n = str.length();

    // Swap character starting from two corners
    for(int i = 0; i < n/2; i++) {
        // by time we get to middle, we exit loop
        swap(str[i], str[n-i-1]);
    }
}

string str = "geeksforgeeks";
reverseStr(str);
cout << str;

// 2. Use inbuilt 'reverse' function
string str = "geeksforgeeks";
// Reverse str[begin..end]
reverse(str.begin(), str.end());
cout << str;

// 3. Only printing reverse
void reverse(string str) {
    for(int i = str.length()-1; i >= 0; i--) {
        cout << str[i];
    }
}

string str = "geeksforgeeks";
reverse(str);

// Comparing strings and checking palindrome
// 1. Iteration: Check if a string str is a palindrome
void isPalindrome(string str) {
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = str.length() - 1;

    // Keep comparing characters while they are same
    while(h > l) {
        if(str[l++] != str[h--]) {
            cout << str << " is Not Palindrome" << endl;
            return;
        }
    }
    cout << str << " is Palindrome" << endl;
}

isPalindrome("abba");
isPalindrome("abbccbba");
isPalindrome("geeks");

// 2. Recursion: Check if string is a palindrome
bool isPalRec(string str, int l, int r) {
    // if there is only one character
    if(l == r) {
        return true;
    }

    // If first and last characters don't match
    if(str[l] != str[r]) {
        return false;
    }

    // if there are more than 2 characters, check if middle
    // substring is also palindrome or not
    if(l < r+1) {
        return isPalRec(str, l+1, r-1);
    }
    return true;
}

bool isPalindrome(string str)
{
    int n = str.length();

    // An empty string is considered a palindrome
    if(n == 0) {
        return true;
    }

    return isPalRec(str, 0, n-1);
}

string s = "geeg";

if(isPalindrome) {
    cout << "Yes" << endl;
}
else {
    cout << "No" << endl;
}

// Finding duplicates in a string, Time Complexity: O(n)
// Character range is from 0 to 255
#define NO_OF_CHARS 256
class Solution {
    public:
        // Fills count array with frequency of characters
        void fillCharCounts(string str, vector<int> count) {
            for(int i = 0; str[i]; i++) {
                // only increments count for each duplicate
                count[str[i]]++;
            }
        }

        // Print duplicates present in passed string
        void printDups(string str) {
            // Create vector of size 256 and fill count
            // of every character in it
            vector<int> count(NO_OF_CHARS, 0);
            fillCharCounts(str, count);

            // Print characters having count more than
            for(int i = 0; i < NO_OF_CHARS; i++) {
                if(count[i] > 1) {
                    cout << i << ", count = " << count[i] << endl;
                }
            }
        }
};

Solution soln;
string s1 = "test string";
soln.printDups(s1);

// Finding duplicates in a string using Bitwise Operations

// Checking if 2 strings are anagram

// Permutation of string
~~~