# Running JS Code

Run JavaScript file from terminal using NodeJS runtime. Install NodeJS:

~~~bash
sudo apt -y update
sudo apt -y upgrade
sudo apt -y install build-essential
wget -qO- https://raw.githubusercontent.com/nvm-sh/nvm/v0.35.2/install.sh | bash

nvm install --lts

echo "nvm use --lts" >> ~/.bash_profile
~~~

## Approach 1: Run JS Code using NodeJS

~~~bash
node Essentials/Array/index.js 1
~~~

> Note: 1 is for true meaning the program is run from the command line. If you run it using Webpack Dev Server, no need to worry about an argument passed into the program.

## Approach 2: Run JS Code using Webpack

Inside your project, run npm init to generate a blank `package.json`. package.json records which packages your app depends on.

### NPM Initialization

~~~bash
npm init
~~~

Example of input questions you will be asked:

~~~bash
package name: (array)
version: (1.0.0)
description: Declares, initializes and prints array elements.
entry point: (index.js)
test command:
git repository:
keywords:
author: James Medel
license: (ISC)

About to write to /GitHub/{user}/Data-Structures-and-Algorithms/projects/JavaScript/Essentials/Array/package.json:

{
  "name": "{project name}",
  "version": "1.0.0",
  "description": "Declares, initializes and prints array elements.",
  "main": "index.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "author": "{Full Name}",
  "license": "ISC"
}


Is this OK? (yes) yes
~~~

### Webpack Installation

Inside your project directory you ran `npm init`, building tool Webpack will be added to `package.json` for buildinng JavaScript code during development, install Webpack and developement server:

~~~bash
npm install --save-dev webpack webpack-cli webpack-dev-server
~~~

> Note: `sudo` may be needed for permissions 

If you get [NPM install - rename error on WSL](https://forum.openzeppelin.com/t/npm-err-error-eacces-permission-denied-rename-wsl-with-vs-code-open/1549/2), close VS Studio Code, then try to run npm install again. It worked for me.

### Webpack Scripts

Add two scripts to `package.json` file in the `scripts` section:

~~~json
{
  ...
  "scripts": {
    "dev": "webpack-dev-server --env.dev",
    "build": "webpack"
  },
  ...
}
~~~

`dev` script will start development server, passing the `{env: 'dev'}` option to our config file. The `build` script will saave a single `.js` file on the filesystem for serving from a production server. We'll use these scripts to bundle and test our app.

### Webpack Configuration

Inside your project directory where you ran `npm init`, create a new file `webpack.config.js`. Webpack is configured using a separate config file. This file exports a configuration object or function, which returns a object, which the webpack compiler will use when run from the command line as `webpack`. Add the following code to the file:

~~~js
module.exports = options => {
  return {
    entry: './index.js',
    output: {
      filename: 'bundle.js',
    },
  }
}
~~~

There are two fields: the entry point file and output file.

### Essential Files

- `index.js`
- `index.html`

### Running the Webpack Development Server

Inside your project directory, run the development server, execute:

~~~bash
npm run dev
~~~

, which runs the script set up in `package.json`. By navigating to `localhost:8080` in a browser, we should see `index.html`, which will run `index.js` bundled into `bundle.js` displaying the output from our JS code.

>Note: you may be notified that your OS (in my case: Windows 10) has blocked some features of node on all public and private networks. You can allow node to communicate on these networks by checking the boxes. 

The `bundle.js` file will be served from memory by the development server.

### Running the Webpack Production Server

For production builds, use

~~~bash
npm run build
~~~

, which will build an optimized `bundle.js`, which will be saved to the filesystem.

## Further Reading

- [Windows 10 Fall Creators Update - Installing Node.js on Windows Subsystem for Linux (WSL)](https://gist.github.com/noygal/6b7b1796a92d70e24e35f94b53722219)
- [Webpack - React Express](http://www.react.express/webpack)