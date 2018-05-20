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
    public partial class SingleInput : Form
    {
        public SingleInput()
        {
            InitializeComponent();
        }

        private void Button_SI_Click(object sender, EventArgs e)
        {
            SingleInput.flag_select = false;
            SingleInput.single_input_text = "";

            SingleInput.single_input_text = textBox_SingleInput.Text;
            if (textBox_SingleInput.Text != "")
                SingleInput.flag_select = true;
            this.Close();
        }
    }
}
