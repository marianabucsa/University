namespace AthleticsCompetition
{
    partial class ChildEnrollmentPage
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
            this.childEnrollmentBox = new System.Windows.Forms.GroupBox();
            this.textAgeChild = new System.Windows.Forms.TextBox();
            this.enrollButton = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.RoundsCheckBox = new System.Windows.Forms.CheckedListBox();
            this.textLastNameChild = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textFirstNameChild = new System.Windows.Forms.TextBox();
            this.tableNumberChildrenPerRound = new System.Windows.Forms.DataGridView();
            this.childEnrollmentBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tableNumberChildrenPerRound)).BeginInit();
            this.SuspendLayout();
            // 
            // childEnrollmentBox
            // 
            this.childEnrollmentBox.Controls.Add(this.textAgeChild);
            this.childEnrollmentBox.Controls.Add(this.enrollButton);
            this.childEnrollmentBox.Controls.Add(this.label3);
            this.childEnrollmentBox.Controls.Add(this.RoundsCheckBox);
            this.childEnrollmentBox.Controls.Add(this.textLastNameChild);
            this.childEnrollmentBox.Controls.Add(this.label1);
            this.childEnrollmentBox.Controls.Add(this.label2);
            this.childEnrollmentBox.Controls.Add(this.textFirstNameChild);
            this.childEnrollmentBox.Location = new System.Drawing.Point(25, 55);
            this.childEnrollmentBox.Name = "childEnrollmentBox";
            this.childEnrollmentBox.Size = new System.Drawing.Size(1200, 322);
            this.childEnrollmentBox.TabIndex = 11;
            this.childEnrollmentBox.TabStop = false;
            this.childEnrollmentBox.Text = "Child Enrollment";
            // 
            // textAgeChild
            // 
            this.textAgeChild.Location = new System.Drawing.Point(18, 258);
            this.textAgeChild.Name = "textAgeChild";
            this.textAgeChild.Size = new System.Drawing.Size(187, 26);
            this.textAgeChild.TabIndex = 4;
            // 
            // enrollButton
            // 
            this.enrollButton.Location = new System.Drawing.Point(949, 157);
            this.enrollButton.Name = "enrollButton";
            this.enrollButton.Size = new System.Drawing.Size(152, 45);
            this.enrollButton.TabIndex = 8;
            this.enrollButton.Text = "Enroll";
            this.enrollButton.UseVisualStyleBackColor = true;
            this.enrollButton.Click += new System.EventHandler(this.enrollButton_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(14, 235);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(38, 20);
            this.label3.TabIndex = 5;
            this.label3.Text = "Age";
            // 
            // RoundsCheckBox
            // 
            this.RoundsCheckBox.FormattingEnabled = true;
            this.RoundsCheckBox.Items.AddRange(new object[] {
            "50 m Round",
            "100 m Round",
            "1000 m Round",
            "1500 m Round"});
            this.RoundsCheckBox.Location = new System.Drawing.Point(327, 86);
            this.RoundsCheckBox.Name = "RoundsCheckBox";
            this.RoundsCheckBox.Size = new System.Drawing.Size(507, 211);
            this.RoundsCheckBox.TabIndex = 7;
            // 
            // textLastNameChild
            // 
            this.textLastNameChild.Location = new System.Drawing.Point(18, 176);
            this.textLastNameChild.Name = "textLastNameChild";
            this.textLastNameChild.Size = new System.Drawing.Size(187, 26);
            this.textLastNameChild.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 62);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(86, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "First Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(14, 150);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(86, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "Last Name";
            // 
            // textFirstNameChild
            // 
            this.textFirstNameChild.Location = new System.Drawing.Point(14, 85);
            this.textFirstNameChild.Name = "textFirstNameChild";
            this.textFirstNameChild.Size = new System.Drawing.Size(191, 26);
            this.textFirstNameChild.TabIndex = 0;
            // 
            // tableNumberChildrenPerRound
            // 
            this.tableNumberChildrenPerRound.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.tableNumberChildrenPerRound.Location = new System.Drawing.Point(415, 407);
            this.tableNumberChildrenPerRound.Name = "tableNumberChildrenPerRound";
            this.tableNumberChildrenPerRound.RowHeadersWidth = 62;
            this.tableNumberChildrenPerRound.RowTemplate.Height = 28;
            this.tableNumberChildrenPerRound.Size = new System.Drawing.Size(399, 221);
            this.tableNumberChildrenPerRound.TabIndex = 12;
            // 
            // ChildEnrollmentPage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1250, 664);
            this.Controls.Add(this.tableNumberChildrenPerRound);
            this.Controls.Add(this.childEnrollmentBox);
            this.Name = "ChildEnrollmentPage";
            this.Text = "ChildEnrollment";
            this.childEnrollmentBox.ResumeLayout(false);
            this.childEnrollmentBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tableNumberChildrenPerRound)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox childEnrollmentBox;
        private System.Windows.Forms.TextBox textAgeChild;
        private System.Windows.Forms.Button enrollButton;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.CheckedListBox RoundsCheckBox;
        private System.Windows.Forms.TextBox textLastNameChild;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textFirstNameChild;
        private System.Windows.Forms.DataGridView tableNumberChildrenPerRound;
    }
}