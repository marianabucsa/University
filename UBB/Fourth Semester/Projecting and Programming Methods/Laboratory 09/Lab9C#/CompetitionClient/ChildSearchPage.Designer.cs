namespace CompetitionClient
{
    partial class ChildSearchPage
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
            this.textFirstNameChild = new System.Windows.Forms.TextBox();
            this.textLastNameChild = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.searchByNameButton = new System.Windows.Forms.Button();
            this.searchChildTable = new System.Windows.Forms.DataGridView();
            this.roundsComboBox = new System.Windows.Forms.ComboBox();
            this.ageGroupsComboBox = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.searchChildTable)).BeginInit();
            this.SuspendLayout();
            // 
            // textFirstNameChild
            // 
            this.textFirstNameChild.Location = new System.Drawing.Point(625, 88);
            this.textFirstNameChild.Name = "textFirstNameChild";
            this.textFirstNameChild.Size = new System.Drawing.Size(209, 26);
            this.textFirstNameChild.TabIndex = 0;
            // 
            // textLastNameChild
            // 
            this.textLastNameChild.Location = new System.Drawing.Point(625, 221);
            this.textLastNameChild.Name = "textLastNameChild";
            this.textLastNameChild.Size = new System.Drawing.Size(209, 26);
            this.textLastNameChild.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(621, 50);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(86, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "First Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(621, 168);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(86, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "Last Name";
            // 
            // searchByNameButton
            // 
            this.searchByNameButton.Location = new System.Drawing.Point(678, 307);
            this.searchByNameButton.Name = "searchByNameButton";
            this.searchByNameButton.Size = new System.Drawing.Size(94, 34);
            this.searchByNameButton.TabIndex = 4;
            this.searchByNameButton.Text = "Search";
            this.searchByNameButton.UseVisualStyleBackColor = true;
            this.searchByNameButton.Click += new System.EventHandler(this.searchByNameButton_Click);
            // 
            // searchChildTable
            // 
            this.searchChildTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.searchChildTable.Location = new System.Drawing.Point(12, 23);
            this.searchChildTable.Name = "searchChildTable";
            this.searchChildTable.RowHeadersWidth = 62;
            this.searchChildTable.RowTemplate.Height = 28;
            this.searchChildTable.Size = new System.Drawing.Size(571, 403);
            this.searchChildTable.TabIndex = 5;
            // 
            // roundsComboBox
            // 
            this.roundsComboBox.FormattingEnabled = true;
            this.roundsComboBox.Items.AddRange(new object[] {
            "50 m Round",
            "100 m Round",
            "1000 m Round",
            "1500 m Round"});
            this.roundsComboBox.Location = new System.Drawing.Point(986, 98);
            this.roundsComboBox.Name = "roundsComboBox";
            this.roundsComboBox.Size = new System.Drawing.Size(210, 28);
            this.roundsComboBox.TabIndex = 6;
            this.roundsComboBox.SelectedIndexChanged += new System.EventHandler(this.roundsComboBox_SelectedIndexChanged);
            // 
            // ageGroupsComboBox
            // 
            this.ageGroupsComboBox.FormattingEnabled = true;
            this.ageGroupsComboBox.Items.AddRange(new object[] {
            "6-8 years old",
            "9-11 years old",
            "12-15 years old"});
            this.ageGroupsComboBox.Location = new System.Drawing.Point(986, 221);
            this.ageGroupsComboBox.Name = "ageGroupsComboBox";
            this.ageGroupsComboBox.Size = new System.Drawing.Size(210, 28);
            this.ageGroupsComboBox.TabIndex = 7;
            this.ageGroupsComboBox.SelectedIndexChanged += new System.EventHandler(this.ageGroupsComboBox_SelectedIndexChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(982, 61);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 20);
            this.label3.TabIndex = 8;
            this.label3.Text = "Rounds";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(982, 198);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(95, 20);
            this.label4.TabIndex = 9;
            this.label4.Text = "Age Groups";
            // 
            // ChildSearchPage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1254, 463);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.ageGroupsComboBox);
            this.Controls.Add(this.roundsComboBox);
            this.Controls.Add(this.searchChildTable);
            this.Controls.Add(this.searchByNameButton);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textLastNameChild);
            this.Controls.Add(this.textFirstNameChild);
            this.Name = "ChildSearchPage";
            this.Text = "ChildSearchPage";
            ((System.ComponentModel.ISupportInitialize)(this.searchChildTable)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textFirstNameChild;
        private System.Windows.Forms.TextBox textLastNameChild;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button searchByNameButton;
        private System.Windows.Forms.DataGridView searchChildTable;
        private System.Windows.Forms.ComboBox roundsComboBox;
        private System.Windows.Forms.ComboBox ageGroupsComboBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
    }
}