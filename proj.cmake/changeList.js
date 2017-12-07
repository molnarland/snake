const fs = require('fs');

fs.readFile('CMakeLists.txt', {encoding: 'utf8'}, (err, data) =>
{
    if (err) throw err;

    data = data.replace('../oxygine/', '../../oxygine/').replace(/src\//g, '../src/');

    fs.writeFileSync('CMakeLists.txt', data);
});