﻿using CS_Project_Console.Properties;
using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CS_Project_Console
{
    public partial class MainForm : Form
    {
        public static Graphics graphics = null;  // pictureBox_Map的Graphics

        public MainForm()
        {
            InitializeComponent();
            MainForm.graphics = pictureBox_Map.CreateGraphics();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {

        }

        private void ModelSelect_ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void Click_aM(object sender, EventArgs e)
        {
            Form single_input_form = new SingleInput();
            single_input_form.ShowDialog();
            if (SingleInput.flag_select)
            {
                string[] single_output = new String[2];
                single_output[0] = "/a";
                single_output[1] = SingleInput.single_input_text;
                File.WriteAllLines(@"console_input.txt", single_output, Encoding.Default);
                Program.InterFace2();
                At[] file_list = Program.ReadTextLine();
                ResetMap();
                DrawTool.Drawing(file_list);
            }
            else
                MessageBox.Show("输入不为空！");
        }

        private void Click_cM(object sender, EventArgs e)
        {
            Form single_input_form = new SingleInput();
            single_input_form.ShowDialog();
            if (SingleInput.flag_select)
            {
                string[] single_output = new String[2];
                single_output[0] = "/c";
                single_output[1] = SingleInput.single_input_text;
                File.WriteAllLines(@"console_input.txt", single_output, Encoding.Default);
                Program.InterFace2();
                At[] file_list = Program.ReadTextLine();
                ResetMap();
                DrawTool.Drawing(file_list);
            }
            else
                MessageBox.Show("输入不为空！");
        }

        private void Click_bM(object sender, EventArgs e)
        {
            Form double_input_form = new DoubleInput();
            double_input_form.ShowDialog();
            if (DoubleInput.flag_select)
            {
                string[] double_output = new string[3];
                double_output[0] = "/b";
                double_output[1] = DoubleInput.double_input_text_from;
                double_output[2] = DoubleInput.double_input_text_to;
                File.WriteAllLines(@"console_input.txt", double_output, Encoding.Default);
                Program.InterFace2();
                At[] file_list = Program.ReadTextLine();
                ResetMap();
                DrawTool.Drawing(file_list);
            }
            else
                MessageBox.Show("输入不为空！");
        }

        private void Click_dM(object sender, EventArgs e)
        {
            Form double_input_form = new DoubleInput();
            double_input_form.ShowDialog();
            if (DoubleInput.flag_select)
            {
                string[] double_output = new string[3];
                double_output[0] = "/d";
                double_output[1] = DoubleInput.double_input_text_from;
                double_output[2] = DoubleInput.double_input_text_to;
                File.WriteAllLines(@"console_input.txt", double_output, Encoding.Default);
                Program.InterFace2();
                At[] file_list = Program.ReadTextLine();
                ResetMap();
                DrawTool.Drawing(file_list);
            }
            else
                MessageBox.Show("输入不为空！");
        }

        private void Click_stationShow(object sender, EventArgs e)
        {
            Form single_input_form = new SingleInput();
            single_input_form.ShowDialog();
            if (SingleInput.flag_select)
            {
                string[] single_output = new String[2];
                single_output[0] = "/s";
                single_output[1] = SingleInput.single_input_text;
                File.WriteAllLines(@"console_input.txt", single_output, Encoding.Default);
                Program.InterFace2();
                At[] file_list = Program.ReadTextLine();
                ResetMap();
                DrawTool.DrawShow(file_list);
            }
            else
                MessageBox.Show("输入不为空！");
        }

        private void Click_ResetMap(object sender, EventArgs e)
        {
            ResetMap();
            GC.Collect();
        }

        /// <summary>
        /// 地图复原，使用原地图覆盖
        /// </summary>
        public void ResetMap()
        {
            Bitmap bitmap = new Bitmap(Resources.subway_map);
            Rectangle r = new Rectangle(0, 0,
                this.pictureBox_Map.Size.Width, this.pictureBox_Map.Size.Height);
            MainForm.graphics.DrawImage(bitmap, r);  // 使用原地图覆盖
        }
    }
}
