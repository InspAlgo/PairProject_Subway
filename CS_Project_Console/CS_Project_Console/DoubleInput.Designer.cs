namespace CS_Project_Console
{
    partial class DoubleInput
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
            this.textBox1_DoubleInput = new System.Windows.Forms.TextBox();
            this.textBox2_DoubleInput = new System.Windows.Forms.TextBox();
            this.Button_DoubleInput = new System.Windows.Forms.Button();
            this.label_from = new System.Windows.Forms.Label();
            this.label_to = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // textBox1_DoubleInput
            // 
            this.textBox1_DoubleInput.Location = new System.Drawing.Point(88, 8);
            this.textBox1_DoubleInput.Name = "textBox1_DoubleInput";
            this.textBox1_DoubleInput.Size = new System.Drawing.Size(131, 21);
            this.textBox1_DoubleInput.TabIndex = 0;
            this.textBox1_DoubleInput.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // textBox2_DoubleInput
            // 
            this.textBox2_DoubleInput.Location = new System.Drawing.Point(88, 43);
            this.textBox2_DoubleInput.Name = "textBox2_DoubleInput";
            this.textBox2_DoubleInput.Size = new System.Drawing.Size(131, 21);
            this.textBox2_DoubleInput.TabIndex = 1;
            // 
            // Button_DoubleInput
            // 
            this.Button_DoubleInput.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.Button_DoubleInput.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Button_DoubleInput.Location = new System.Drawing.Point(57, 77);
            this.Button_DoubleInput.Name = "Button_DoubleInput";
            this.Button_DoubleInput.Size = new System.Drawing.Size(131, 25);
            this.Button_DoubleInput.TabIndex = 2;
            this.Button_DoubleInput.Text = "确定";
            this.Button_DoubleInput.UseVisualStyleBackColor = false;
            this.Button_DoubleInput.Click += new System.EventHandler(this.Button_DI_Click);
            // 
            // label_from
            // 
            this.label_from.AutoSize = true;
            this.label_from.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_from.Location = new System.Drawing.Point(16, 11);
            this.label_from.Name = "label_from";
            this.label_from.Size = new System.Drawing.Size(49, 14);
            this.label_from.TabIndex = 3;
            this.label_from.Text = "起点站";
            // 
            // label_to
            // 
            this.label_to.AutoSize = true;
            this.label_to.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label_to.Location = new System.Drawing.Point(16, 46);
            this.label_to.Name = "label_to";
            this.label_to.Size = new System.Drawing.Size(49, 14);
            this.label_to.TabIndex = 4;
            this.label_to.Text = "终点站";
            // 
            // DoubleInput
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(242, 104);
            this.Controls.Add(this.label_to);
            this.Controls.Add(this.label_from);
            this.Controls.Add(this.Button_DoubleInput);
            this.Controls.Add(this.textBox2_DoubleInput);
            this.Controls.Add(this.textBox1_DoubleInput);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "DoubleInput";
            this.Opacity = 0.9D;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "请输入：";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1_DoubleInput;
        private System.Windows.Forms.TextBox textBox2_DoubleInput;
        private System.Windows.Forms.Button Button_DoubleInput;


        public static bool flag_select = false;  // 判断用户是否选择了'确定'按钮，是则true
        public static string double_input_text_from = "";  // 接收起点站字符串
        public static string double_input_text_to = "";  // 接收终点站字符串
        private System.Windows.Forms.Label label_from;
        private System.Windows.Forms.Label label_to;
    }
}