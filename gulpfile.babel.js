let browserSync = require('browser-sync').create();

import gulp from 'gulp';
import pug from 'gulp-pug2'
import sass from 'gulp-sass';
import autoprefixer from 'gulp-autoprefixer';
import webpack from 'gulp-webpack';
// import babel from 'gulp-babel';

const paths = {
        views: ['./index.pug'],
        styles: [/*'./style.sass'*/],
        js: ['./src/**/*.js']
    },
    basePath = './',
    base = {base: basePath};


function reloadBrowser(done)
{
    browserSync.reload();
    done();
}


gulp.task('pug', (done) =>
{
    gulp.src(paths.views, base)
        .pipe(pug({
            pretty: true,
            cache: false
        }))
        .pipe(gulp.dest(basePath));

    reloadBrowser(done);
});

gulp.task('sass', (done) =>
{
    gulp.src(paths.styles, base)
        .pipe(sass({indentedSyntax: true/*, outputStyle: 'compressed'*/}).on('error', sass.logError))
        .pipe(autoprefixer({
            browsers: ['last 10 versions'],
            cascade: true
        }))
        .pipe(gulp.dest(basePath));

    reloadBrowser(done);
});

gulp.task('js', (done) =>
{
    gulp.src(paths.js)
        .pipe(webpack(require('./webpack.config.js')))
        .pipe(gulp.dest('dist/'));

    reloadBrowser(done);
});

gulp.task('server', ['pug', 'sass', 'js'], () =>
{
    browserSync.init(['index.html'], {
        server: './',
        open: false
    });
});

function watch ()
{
    gulp.watch(paths.views, ['pug']);
    gulp.watch(paths.styles, ['sass']);
    gulp.watch(paths.js, ['js']);
}

gulp.task('watch', watch());

gulp.task('default', ['server']);
