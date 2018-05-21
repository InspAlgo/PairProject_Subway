using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CS_Project_Console
{
    public partial class DoubleInput : Form
    {
        public DoubleInput()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Button_DI_Click(object sender, EventArgs e)
        {
            DoubleInput.flag_select = false;
            DoubleInput.double_input_text_from = "";
            DoubleInput.double_input_text_to = "";

            DoubleInput.double_input_text_from = textBox1_DoubleInput.Text;
            DoubleInput.double_input_text_to = textBox2_DoubleInput.Text;

            if (DoubleInput.double_input_text_from != ""
                && DoubleInput.double_input_text_to != "")
                DoubleInput.flag_select = true;

            this.Close();
        }

        /// <summary>
        /// 回车确定功能
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void textBox1_DI_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
                Button_DI_Click(sender, e);  // 调用确定按钮的事件触发函数
        }

        private void textBox2_DI_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
                Button_DI_Click(sender, e);
        }
    }
}
