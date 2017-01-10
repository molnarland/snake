export default class Snake
{
    /**
     * @param {string} color
     * @param {number} bodyWidth
     * @param {number} bodyHeight
     */
    constructor ({color, bodyWidth, bodyHeight})
    {
        this.color = color;
        this.bodyWidth = bodyWidth;
        this.bodyHeight = bodyHeight;

        this.bodyDatas = [];
    }

    /**
     * @param {number} x
     * @param {number} y
     */
    drawBody ({x, y})
    {
        this.canvas.fillStart();

        this.canvas.ctx.rect(
            x, y,
            this.canvas.getResponsiveWidth(this.bodyWidth),
            this.canvas.getResponsiveHeight(this.bodyHeight)
        );
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
    move (callback)
    {
        this.canvas.clear();

        let bodyDatas = this.bodyDatas;
        this.bodyDatas = [];

        for (let bodyData of bodyDatas)
        {
            callback(bodyData);
        }
    }

    moveLeft ()
    {
        this.move((bodyData) =>
        {
            this.drawBody({
                x: bodyData.x + this.bodyWidth,
                y: bodyData.y
            });
        });
    }

    moveTop ()
    {
        this.move((bodyData) =>
        {
            this.drawBody({
                x: bodyData.x,
                y: bodyData.y + this.bodyHeight
            })
        });
    }
}