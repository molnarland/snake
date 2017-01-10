export default class Canvas
{
    constructor ()
    {
        this.canvas = document.getElementById("canvas");
        this.ctx = this.canvas.getContext("2d");
    }

    fillStart ()
    {
        this.ctx.beginPath()
    }

    fillEnd ()
    {
        this.ctx.fill();
        this.ctx.closePath();
    }

    setColor (color)
    {
        this.ctx.fillStyle = color;
    }


}