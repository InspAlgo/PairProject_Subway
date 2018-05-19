using System.Windows.Forms;  // 响应滚轮要用的声明
using System.Drawing;
namespace CS_Project_Console
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.pictureBox_background = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_background)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox_background
            // 
            this.pictureBox_background.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pictureBox_background.BackgroundImage")));
            this.pictureBox_background.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox_background.Location = new System.Drawing.Point(12, 12);
            this.pictureBox_background.Name = "pictureBox_background";
            this.pictureBox_background.Size = new System.Drawing.Size(746, 589);
            this.pictureBox_background.TabIndex = 0;
            this.pictureBox_background.TabStop = false;
 
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(985, 613);
            this.Controls.Add(this.pictureBox_background);
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.MouseWheel += new System.Windows.Forms.MouseEventHandler(this.MainForm_MouseWheel);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_background)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox_background;

        /// <summary>
        /// 滚轮缩放地图
        /// </summary>
        private void MainForm_MouseWheel(object sender, MouseEventArgs e)  
        {
            var t = pictureBox_background.Size;
            t.Width += e.Delta;
            t.Height += e.Delta;
            pictureBox_background.Size = t;
        }


    }
}