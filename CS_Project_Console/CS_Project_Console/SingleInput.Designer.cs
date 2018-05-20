namespace CS_Project_Console
{
    partial class SingleInput
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
            this.textBox_SingleInput = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.Button_SingleInput = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBox_SingleInput
            // 
            this.textBox_SingleInput.Location = new System.Drawing.Point(14, 12);
            this.textBox_SingleInput.Name = "textBox_SingleInput";
            this.textBox_SingleInput.Size = new System.Drawing.Size(202, 21);
            this.textBox_SingleInput.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(76, 0);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(8, 8);
            this.button1.TabIndex = 1;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // Button_SingleInput
            // 
            this.Button_SingleInput.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.Button_SingleInput.Location = new System.Drawing.Point(49, 67);
            this.Button_SingleInput.Name = "Button_SingleInput";
            this.Button_SingleInput.Size = new System.Drawing.Size(131, 25);
            this.Button_SingleInput.TabIndex = 2;
            this.Button_SingleInput.Text = "确定";
            this.Button_SingleInput.UseVisualStyleBackColor = false;
            this.Button_SingleInput.Click += new System.EventHandler(this.Button_SI_Click);
            // 
            // SingleInput
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(228, 104);
            this.Controls.Add(this.Button_SingleInput);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox_SingleInput);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SingleInput";
            this.Opacity = 0.9D;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "请输入：";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox_SingleInput;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button Button_SingleInput;

        public static bool flag_select=false;
        public static string single_input_text = "";
    }
}