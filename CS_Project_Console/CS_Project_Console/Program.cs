﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;

namespace CS_Project_Console
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 1 && args[0].ToLower() == "/g")
            {
                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);
                Application.Run(new MainForm());
            }
            else if (args.Length == 2 && args[0].ToLower() == "/a")
            {
                File.WriteAllLines(@"console_input.txt", args, Encoding.Default);
                InterFace();
            }
            else if (args.Length == 3 &&
                (args[0].ToLower() == "/b" || args[0].ToLower() == "/d"))
            {
                File.WriteAllLines(@"console_input.txt", args, Encoding.Default);
                InterFace();
            }
            else if (args.Length == 2 &&
                (args[0].ToLower() == "/c" || args[0].ToLower() == "/z"))
            {
                File.WriteAllLines(@"console_input.txt", args, Encoding.Default);
                InterFace();
            }
            else
            {
                Console.WriteLine("Error: Invalid input parameter.");
                Console.WriteLine("Please try again!");
            }
        }

        /// <summary>
        /// 控制台使用的DLL调用函数
        /// </summary>
        [DllImport("DLLCS.dll", EntryPoint = "ConsoleInterface")]
        public static extern void InterFace();

        /// <summary>
        /// 界面使用的DLL调用函数
        /// </summary>
        [DllImport("DLLCS.dll", EntryPoint = "GUIInterface")]
        public static extern void InterFace2();

        /// <summary>
        /// 按行读取文本文件内容，返回一个ArrayList，每一个元素是一行内容
        /// </summary>
        /// <param name="file_path"></param>
        /// <returns></returns>
        public static At[] ReadTextLine()
        {
            StreamReader sr = new StreamReader(@"gui_print.txt", Encoding.Default);
            String line;
            At[] station_at = new At[900];
            At.num = 0;
            while ((line = sr.ReadLine()) != null)
            {
                if (line.Equals("Error") == true)
                {
                    MessageBox.Show(sr.ReadLine());
                    return null;
                }
                        
                int flag_space = line.IndexOf(' ');
                float.TryParse(line.Substring(0, flag_space), out station_at[At.num].x);
                float.TryParse(line.Substring(flag_space + 1), out station_at[At.num].y);
                At.num++;
            }
            return station_at;
        }
    }
}
