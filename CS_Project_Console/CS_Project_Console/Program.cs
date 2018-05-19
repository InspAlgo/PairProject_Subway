using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CS_Project_Console
{

    class Program
    {

        static void Main(string[] args)
        {
            if (args.Length == 2 && args[0].ToLower() == "/g")
            {
                //File.WriteAllLines(@"console_input.txt", args, Encoding.Default);
                //InterFace();
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

        [DllImport("DLLCS.dll", EntryPoint = "Interface")]
        public static extern void InterFace();
    }
}
