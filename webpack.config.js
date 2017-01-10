module.exports = {
    entry: {
        main: "./src/entry.js"
    },
    output: {
        path: __dirname + '/dist',
        filename: 'main.js',
        pathinfo: false
    },
    module: {
        loaders: [
            {
                test: /\.js$/,
                exclude: /node_modules/,
                loader: 'babel-loader',
                query: {
                    presets: ["es2017", "es2016", "es2015"]
                }
            }
        ]
    },
    devtool: 'source-map',
};