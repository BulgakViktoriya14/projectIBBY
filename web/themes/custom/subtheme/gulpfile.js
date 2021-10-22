const gulp = require('gulp'),
  sass = require('gulp-sass'),
  autoprefixer = require('gulp-autoprefixer'),
  sourcemaps = require('gulp-sourcemaps')

// Compile sass into CSS & auto-inject into browsers
gulp.task('sass', () => {
  return gulp.src(['scss/style.scss'])
    .pipe(sourcemaps.init())
    .pipe(sass().on('error', sass.logError))
    .pipe(autoprefixer({
      remove: false,
      grid: true,
    }))
    .pipe(sass({outputStyle: 'compressed'}))
    .pipe(sourcemaps.write())
    .pipe(gulp.dest('css'));
});

// Move the javascript files into our js folder
gulp.task('js', () => {
  return gulp.src(['node_modules/bootstrap/dist/js/bootstrap.min.js',
    'node_modules/bootstrap/dist/js/bootstrap.min.js.map',
    'node_modules/popper.js/dist/umd/popper.min.js',
    'node_modules/popper.js/dist/umd/popper.min.js.map'])
    .pipe(gulp.dest('js'));
});


gulp.task('default', () => {
  gulp.watch(['scss/*.scss', 'scss/*/*.scss', 'scss/*/*/*.scss']).on('change', gulp.parallel('sass'))
  gulp.parallel('js')
});
