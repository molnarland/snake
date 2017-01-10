/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId])
/******/ 			return installedModules[moduleId].exports;
/******/
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			exports: {},
/******/ 			id: moduleId,
/******/ 			loaded: false
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.loaded = true;
/******/
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/
/******/
/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;
/******/
/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;
/******/
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";
/******/
/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(0);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ function(module, exports, __webpack_require__) {

	'use strict';
	
	var _Snake = __webpack_require__(1);
	
	var _Snake2 = _interopRequireDefault(_Snake);
	
	var _Rectangle = __webpack_require__(2);
	
	var _Rectangle2 = _interopRequireDefault(_Rectangle);
	
	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }
	
	// const s = new Snake({
	//     color: 'pink',
	//     bodyWidth: 5,
	//     bodyHeight: 10
	// });
	// s.drawBody({x: 10, y: 10});
	// s.drawBody({x: 15, y: 10});
	//
	//
	//
	//
	//
	// setInterval(() =>
	// {
	//     s.moveLeft();
	// }, 100);
	
	new _Rectangle2.default();

/***/ },
/* 1 */
/***/ function(module, exports) {

	"use strict";
	
	Object.defineProperty(exports, "__esModule", {
	    value: true
	});
	
	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();
	
	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
	
	var Snake = function () {
	    /**
	     * @param {string} color
	     * @param {number} bodyWidth
	     * @param {number} bodyHeight
	     */
	    function Snake(_ref) {
	        var color = _ref.color,
	            bodyWidth = _ref.bodyWidth,
	            bodyHeight = _ref.bodyHeight;
	
	        _classCallCheck(this, Snake);
	
	        this.color = color;
	        this.bodyWidth = bodyWidth;
	        this.bodyHeight = bodyHeight;
	
	        this.bodyDatas = [];
	    }
	
	    /**
	     * @param {number} x
	     * @param {number} y
	     */
	
	
	    _createClass(Snake, [{
	        key: "drawBody",
	        value: function drawBody(_ref2) {
	            var x = _ref2.x,
	                y = _ref2.y;
	
	            this.canvas.fillStart();
	
	            this.canvas.ctx.rect(x, y, this.canvas.getResponsiveWidth(this.bodyWidth), this.canvas.getResponsiveHeight(this.bodyHeight));
	            this.canvas.ctx.fillStyle = this.color;
	
	            this.canvas.fillEnd();
	
	            this.bodyDatas.push({
	                x: x,
	                y: y
	            });
	        }
	
	        /**
	         * @param {function} callback
	         */
	
	    }, {
	        key: "move",
	        value: function move(callback) {
	            this.canvas.clear();
	
	            var bodyDatas = this.bodyDatas;
	            this.bodyDatas = [];
	
	            var _iteratorNormalCompletion = true;
	            var _didIteratorError = false;
	            var _iteratorError = undefined;
	
	            try {
	                for (var _iterator = bodyDatas[Symbol.iterator](), _step; !(_iteratorNormalCompletion = (_step = _iterator.next()).done); _iteratorNormalCompletion = true) {
	                    var bodyData = _step.value;
	
	                    callback(bodyData);
	                }
	            } catch (err) {
	                _didIteratorError = true;
	                _iteratorError = err;
	            } finally {
	                try {
	                    if (!_iteratorNormalCompletion && _iterator.return) {
	                        _iterator.return();
	                    }
	                } finally {
	                    if (_didIteratorError) {
	                        throw _iteratorError;
	                    }
	                }
	            }
	        }
	    }, {
	        key: "moveLeft",
	        value: function moveLeft() {
	            var _this = this;
	
	            this.move(function (bodyData) {
	                _this.drawBody({
	                    x: bodyData.x + _this.bodyWidth,
	                    y: bodyData.y
	                });
	            });
	        }
	    }, {
	        key: "moveTop",
	        value: function moveTop() {
	            var _this2 = this;
	
	            this.move(function (bodyData) {
	                _this2.drawBody({
	                    x: bodyData.x,
	                    y: bodyData.y + _this2.bodyHeight
	                });
	            });
	        }
	    }]);
	
	    return Snake;
	}();
	
	exports.default = Snake;

/***/ },
/* 2 */
/***/ function(module, exports, __webpack_require__) {

	'use strict';
	
	Object.defineProperty(exports, "__esModule", {
	    value: true
	});
	
	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();
	
	var _Draw2 = __webpack_require__(3);
	
	var _Draw3 = _interopRequireDefault(_Draw2);
	
	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }
	
	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
	
	function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }
	
	function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }
	
	var Rectangle = function (_Draw) {
	    _inherits(Rectangle, _Draw);
	
	    function Rectangle() {
	        _classCallCheck(this, Rectangle);
	
	        return _possibleConstructorReturn(this, (Rectangle.__proto__ || Object.getPrototypeOf(Rectangle)).call(this));
	    }
	
	    _createClass(Rectangle, [{
	        key: 'draw',
	        value: function draw() {}
	    }]);
	
	    return Rectangle;
	}(_Draw3.default);
	
	exports.default = Rectangle;

/***/ },
/* 3 */
/***/ function(module, exports) {

	"use strict";
	
	Object.defineProperty(exports, "__esModule", {
	    value: true
	});
	
	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();
	
	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
	
	var Canvas = function () {
	    function Canvas() {
	        _classCallCheck(this, Canvas);
	
	        this.canvas = document.getElementById("canvas");
	        this.ctx = this.canvas.getContext("2d");
	    }
	
	    _createClass(Canvas, [{
	        key: "fillStart",
	        value: function fillStart() {
	            this.ctx.beginPath();
	        }
	    }, {
	        key: "fillEnd",
	        value: function fillEnd() {
	            this.ctx.fill();
	            this.ctx.closePath();
	        }
	    }, {
	        key: "setColor",
	        value: function setColor(color) {
	            this.ctx.fillStyle = color;
	        }
	    }]);
	
	    return Canvas;
	}();
	
	exports.default = Canvas;

/***/ }
/******/ ]);
//# sourceMappingURL=main.js.map