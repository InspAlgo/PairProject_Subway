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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.ModelSelect_ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aModel_ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.bModel_ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.cModel_ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.dModel_ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.stationShow_ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ResetMap_ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pictureBox_Map = new System.Windows.Forms.PictureBox();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Map)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ModelSelect_ToolStripMenuItem,
            this.ResetMap_ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1050, 25);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // ModelSelect_ToolStripMenuItem
            // 
            this.ModelSelect_ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aModel_ToolStripMenuItem1,
            this.bModel_ToolStripMenuItem1,
            this.cModel_ToolStripMenuItem1,
            this.dModel_ToolStripMenuItem1,
            this.stationShow_ToolStripMenuItem});
            this.ModelSelect_ToolStripMenuItem.Name = "ModelSelect_ToolStripMenuItem";
            this.ModelSelect_ToolStripMenuItem.Size = new System.Drawing.Size(68, 21);
            this.ModelSelect_ToolStripMenuItem.Text = "模式选择";
            this.ModelSelect_ToolStripMenuItem.Click += new System.EventHandler(this.ModelSelect_ToolStripMenuItem_Click);
            // 
            // aModel_ToolStripMenuItem1
            // 
            this.aModel_ToolStripMenuItem1.Name = "aModel_ToolStripMenuItem1";
            this.aModel_ToolStripMenuItem1.Size = new System.Drawing.Size(124, 22);
            this.aModel_ToolStripMenuItem1.Text = "/a 模式";
            this.aModel_ToolStripMenuItem1.Click += new System.EventHandler(this.Click_aM);
            // 
            // bModel_ToolStripMenuItem1
            // 
            this.bModel_ToolStripMenuItem1.Name = "bModel_ToolStripMenuItem1";
            this.bModel_ToolStripMenuItem1.Size = new System.Drawing.Size(124, 22);
            this.bModel_ToolStripMenuItem1.Text = "/b 模式";
            this.bModel_ToolStripMenuItem1.Click += new System.EventHandler(this.Click_bM);
            // 
            // cModel_ToolStripMenuItem1
            // 
            this.cModel_ToolStripMenuItem1.Name = "cModel_ToolStripMenuItem1";
            this.cModel_ToolStripMenuItem1.Size = new System.Drawing.Size(124, 22);
            this.cModel_ToolStripMenuItem1.Text = "/c 模式";
            this.cModel_ToolStripMenuItem1.Click += new System.EventHandler(this.Click_cM);
            // 
            // dModel_ToolStripMenuItem1
            // 
            this.dModel_ToolStripMenuItem1.Name = "dModel_ToolStripMenuItem1";
            this.dModel_ToolStripMenuItem1.Size = new System.Drawing.Size(124, 22);
            this.dModel_ToolStripMenuItem1.Text = "/d 模式";
            this.dModel_ToolStripMenuItem1.Click += new System.EventHandler(this.Click_dM);
            // 
            // stationShow_ToolStripMenuItem
            // 
            this.stationShow_ToolStripMenuItem.Name = "stationShow_ToolStripMenuItem";
            this.stationShow_ToolStripMenuItem.Size = new System.Drawing.Size(124, 22);
            this.stationShow_ToolStripMenuItem.Text = "站点显示";
            this.stationShow_ToolStripMenuItem.Click += new System.EventHandler(this.Click_stationShow);
            // 
            // ResetMap_ToolStripMenuItem
            // 
            this.ResetMap_ToolStripMenuItem.Name = "ResetMap_ToolStripMenuItem";
            this.ResetMap_ToolStripMenuItem.Size = new System.Drawing.Size(68, 21);
            this.ResetMap_ToolStripMenuItem.Text = "地图复原";
            this.ResetMap_ToolStripMenuItem.Click += new System.EventHandler(this.Click_ResetMap);
            // 
            // pictureBox_Map
            // 
            this.pictureBox_Map.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox_Map.BackgroundImage = global::CS_Project_Console.Properties.Resources.subway_map;
            this.pictureBox_Map.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox_Map.Location = new System.Drawing.Point(0, 24);
            this.pictureBox_Map.Name = "pictureBox_Map";
            this.pictureBox_Map.Size = new System.Drawing.Size(1050, 667);
            this.pictureBox_Map.TabIndex = 2;
            this.pictureBox_Map.TabStop = false;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1050, 690);
            this.Controls.Add(this.pictureBox_Map);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "InspAlgo · Beijing Subway";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Map)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }
        private MenuStrip menuStrip1;
        private ToolStripMenuItem ModelSelect_ToolStripMenuItem;
        private ToolStripMenuItem aModel_ToolStripMenuItem1;
        private ToolStripMenuItem bModel_ToolStripMenuItem1;
        private ToolStripMenuItem cModel_ToolStripMenuItem1;
        private ToolStripMenuItem dModel_ToolStripMenuItem1;
        private PictureBox pictureBox_Map;
        private ToolStripMenuItem ResetMap_ToolStripMenuItem;

        #endregion

        private ToolStripMenuItem stationShow_ToolStripMenuItem;
    }
}