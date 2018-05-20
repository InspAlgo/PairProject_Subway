using System;
using System.Collections;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CS_Project_Console
{
    /// <summary>
    /// 站点坐标
    /// </summary>
    public struct At
    {
        public static int num;
        public float x;
        public float y;
    }
    /// <summary>
    /// 封装了一些绘制工具
    /// </summary>
    public static class DrawTool
    {
        /// <summary>
        /// 线画笔颜色，在构造函数中初始化何种颜色
        /// </summary>
        public static Color line_brush_color = new Color();
        /// <summary>
        /// 圈画笔颜色，在构造函数中初始化何种颜色
        /// </summary>
        public static Color circle_brush_color = new Color();

        static DrawTool()
        {
            DrawTool.line_brush_color = Color.FromArgb(55, 66, 77);
            DrawTool.circle_brush_color = Color.FromArgb(123, 222, 144);
        }

        /// <summary>
        /// 绘制指定颜色粗细带箭头的线
        /// </summary>
        public static void DrawArrowLine(Graphics g, float x1, float y1, float x2, float y2, float width)
        {
            Pen p = new Pen(DrawTool.line_brush_color, width);
            p.EndCap = LineCap.ArrowAnchor;  // 定义线尾的样式为箭头
            g.DrawLine(p, x1, y1, x2, y2);
        }

        /// <summary>
        /// 绘制圆心(x,y),半径r,宽度为width的空心圆
        /// </summary>
        public static void DrawCircle(Graphics g, float x, float y, float r, float width)
        {
            Pen p = new Pen(DrawTool.circle_brush_color, width);
            g.DrawEllipse(p, (int)(x - r), (int)(y - r), (int)(2 * r), (int)(2 * r));
        }

        /// <summary>
        /// 需要绘制的车站依次储存在数组中，根据数组信息进行绘制
        /// </summary>
        /// <param name="list"></param>
        public static void Drawing(At[] list)
        {
            for (int i = 0; i < At.num; i++)
            {
                float x1 = list[i].x;
                float y1 = list[i].y;
                DrawTool.DrawCircle(MainForm.graphics, x1, y1, (float)(1), 5);
                if (i != At.num - 1)
                {
                    float x2 = list[i + 1].x;
                    float y2 = list[i + 1].y;
                    DrawTool.DrawArrowLine(MainForm.graphics, x1, y1, x2, y2, 4);
                }
            }
        }
    }
}
