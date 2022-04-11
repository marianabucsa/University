namespace _4._2
{
    partial class Form1
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
            this.Grade_text = new System.Windows.Forms.TextBox();
            this.Rez_text = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.FtoC = new System.Windows.Forms.Button();
            this.CtoF = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Grade_text
            // 
            this.Grade_text.Location = new System.Drawing.Point(257, 60);
            this.Grade_text.Name = "Grade_text";
            this.Grade_text.Size = new System.Drawing.Size(217, 26);
            this.Grade_text.TabIndex = 0;
            // 
            // Rez_text
            // 
            this.Rez_text.Location = new System.Drawing.Point(257, 142);
            this.Rez_text.Name = "Rez_text";
            this.Rez_text.ReadOnly = true;
            this.Rez_text.Size = new System.Drawing.Size(217, 26);
            this.Rez_text.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(84, 65);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(142, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Introduceți gradele";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(88, 147);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(69, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "Rezultat";
            // 
            // FtoC
            // 
            this.FtoC.Location = new System.Drawing.Point(155, 312);
            this.FtoC.Name = "FtoC";
            this.FtoC.Size = new System.Drawing.Size(149, 47);
            this.FtoC.TabIndex = 4;
            this.FtoC.Text = "Convert_FtoC";
            this.FtoC.UseVisualStyleBackColor = true;
            this.FtoC.Click += new System.EventHandler(this.FtoC_Click);
            // 
            // CtoF
            // 
            this.CtoF.Location = new System.Drawing.Point(498, 311);
            this.CtoF.Name = "CtoF";
            this.CtoF.Size = new System.Drawing.Size(142, 48);
            this.CtoF.TabIndex = 5;
            this.CtoF.Text = "Convert_CtoF";
            this.CtoF.UseVisualStyleBackColor = true;
            this.CtoF.Click += new System.EventHandler(this.CtoF_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.CtoF);
            this.Controls.Add(this.FtoC);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Rez_text);
            this.Controls.Add(this.Grade_text);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox Grade_text;
        private System.Windows.Forms.TextBox Rez_text;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button FtoC;
        private System.Windows.Forms.Button CtoF;
    }
}

