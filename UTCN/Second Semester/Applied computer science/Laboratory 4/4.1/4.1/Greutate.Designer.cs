namespace _4._1
{
    partial class Greutate
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
            this.heightField = new System.Windows.Forms.TextBox();
            this.ageField = new System.Windows.Forms.TextBox();
            this.womanBtn = new System.Windows.Forms.Button();
            this.manBtn = new System.Windows.Forms.Button();
            this.stopBtn = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.weightLbl = new System.Windows.Forms.Label();
            this.weightField = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // heightField
            // 
            this.heightField.Location = new System.Drawing.Point(177, 59);
            this.heightField.Name = "heightField";
            this.heightField.Size = new System.Drawing.Size(175, 26);
            this.heightField.TabIndex = 0;
            // 
            // ageField
            // 
            this.ageField.Location = new System.Drawing.Point(177, 127);
            this.ageField.Name = "ageField";
            this.ageField.Size = new System.Drawing.Size(175, 26);
            this.ageField.TabIndex = 1;
            // 
            // womanBtn
            // 
            this.womanBtn.Location = new System.Drawing.Point(45, 255);
            this.womanBtn.Name = "womanBtn";
            this.womanBtn.Size = new System.Drawing.Size(106, 68);
            this.womanBtn.TabIndex = 2;
            this.womanBtn.Text = "Greutate Femei";
            this.womanBtn.UseVisualStyleBackColor = true;
            this.womanBtn.Click += new System.EventHandler(this.WomanBtn_Click);
            // 
            // manBtn
            // 
            this.manBtn.Location = new System.Drawing.Point(283, 260);
            this.manBtn.Name = "manBtn";
            this.manBtn.Size = new System.Drawing.Size(108, 63);
            this.manBtn.TabIndex = 3;
            this.manBtn.Text = "Greutate Bărbați";
            this.manBtn.UseVisualStyleBackColor = true;
            this.manBtn.Click += new System.EventHandler(this.ManBtn_Click);
            // 
            // stopBtn
            // 
            this.stopBtn.Location = new System.Drawing.Point(561, 268);
            this.stopBtn.Name = "stopBtn";
            this.stopBtn.Size = new System.Drawing.Size(75, 43);
            this.stopBtn.TabIndex = 4;
            this.stopBtn.Text = "Gata";
            this.stopBtn.UseVisualStyleBackColor = true;
            this.stopBtn.Click += new System.EventHandler(this.StopBtn_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(45, 59);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 20);
            this.label1.TabIndex = 5;
            this.label1.Text = "Înălțime";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(45, 133);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 20);
            this.label2.TabIndex = 6;
            this.label2.Text = "Vârstă";
            // 
            // weightLbl
            // 
            this.weightLbl.AutoSize = true;
            this.weightLbl.Location = new System.Drawing.Point(429, 97);
            this.weightLbl.Name = "weightLbl";
            this.weightLbl.Size = new System.Drawing.Size(119, 20);
            this.weightLbl.TabIndex = 7;
            this.weightLbl.Text = "Greutate ideală";
            this.weightLbl.Visible = false;
            // 
            // weightField
            // 
            this.weightField.Enabled = false;
            this.weightField.Location = new System.Drawing.Point(561, 91);
            this.weightField.Name = "weightField";
            this.weightField.ReadOnly = true;
            this.weightField.Size = new System.Drawing.Size(166, 26);
            this.weightField.TabIndex = 8;
            this.weightField.Visible = false;
            // 
            // Greutate
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.weightField);
            this.Controls.Add(this.weightLbl);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.stopBtn);
            this.Controls.Add(this.manBtn);
            this.Controls.Add(this.womanBtn);
            this.Controls.Add(this.ageField);
            this.Controls.Add(this.heightField);
            this.Name = "Greutate";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox heightField;
        private System.Windows.Forms.TextBox ageField;
        private System.Windows.Forms.Button womanBtn;
        private System.Windows.Forms.Button manBtn;
        private System.Windows.Forms.Button stopBtn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label weightLbl;
        private System.Windows.Forms.TextBox weightField;
    }
}

