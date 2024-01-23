namespace QLMarket
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.butAdd = new System.Windows.Forms.Button();
            this.butUpdate = new System.Windows.Forms.Button();
            this.butDelete = new System.Windows.Forms.Button();
            this.butSearch = new System.Windows.Forms.Button();
            this.butSort = new System.Windows.Forms.Button();
            this.txtSearch = new System.Windows.Forms.TextBox();
            this.cbbSort = new System.Windows.Forms.ComboBox();
            this.STT = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.MSP1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.TSP1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.SX1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.NN1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.TMH1 = new System.Windows.Forms.DataGridViewComboBoxColumn();
            this.TT1 = new System.Windows.Forms.DataGridViewCheckBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.STT,
            this.MSP1,
            this.TSP1,
            this.SX1,
            this.NN1,
            this.TMH1,
            this.TT1});
            this.dataGridView1.Location = new System.Drawing.Point(31, 33);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(929, 189);
            this.dataGridView1.TabIndex = 0;
            //this.dataGridView1.DataError += new System.Windows.Forms.DataGridViewDataErrorEventHandler(this.dataGridView1_DataError);
            // 
            // butAdd
            // 
            this.butAdd.Location = new System.Drawing.Point(146, 265);
            this.butAdd.Name = "butAdd";
            this.butAdd.Size = new System.Drawing.Size(75, 23);
            this.butAdd.TabIndex = 1;
            this.butAdd.Text = "Add";
            this.butAdd.UseVisualStyleBackColor = true;
            this.butAdd.Click += new System.EventHandler(this.butAdd_Click);
            // 
            // butUpdate
            // 
            this.butUpdate.Location = new System.Drawing.Point(257, 265);
            this.butUpdate.Name = "butUpdate";
            this.butUpdate.Size = new System.Drawing.Size(75, 23);
            this.butUpdate.TabIndex = 2;
            this.butUpdate.Text = "Update";
            this.butUpdate.UseVisualStyleBackColor = true;
            this.butUpdate.Click += new System.EventHandler(this.butUpdate_Click);
            // 
            // butDelete
            // 
            this.butDelete.Location = new System.Drawing.Point(371, 265);
            this.butDelete.Name = "butDelete";
            this.butDelete.Size = new System.Drawing.Size(75, 23);
            this.butDelete.TabIndex = 3;
            this.butDelete.Text = "Delete";
            this.butDelete.UseVisualStyleBackColor = true;
            this.butDelete.Click += new System.EventHandler(this.butDelete_Click);
            // 
            // butSearch
            // 
            this.butSearch.Location = new System.Drawing.Point(481, 265);
            this.butSearch.Name = "butSearch";
            this.butSearch.Size = new System.Drawing.Size(75, 23);
            this.butSearch.TabIndex = 4;
            this.butSearch.Text = "Search";
            this.butSearch.UseVisualStyleBackColor = true;
            this.butSearch.Click += new System.EventHandler(this.butSearch_Click);
            // 
            // butSort
            // 
            this.butSort.Location = new System.Drawing.Point(31, 323);
            this.butSort.Name = "butSort";
            this.butSort.Size = new System.Drawing.Size(75, 23);
            this.butSort.TabIndex = 5;
            this.butSort.Text = "Sort";
            this.butSort.UseVisualStyleBackColor = true;
            this.butSort.Click += new System.EventHandler(this.butSort_Click);
            // 
            // txtSearch
            // 
            this.txtSearch.Location = new System.Drawing.Point(584, 265);
            this.txtSearch.Name = "txtSearch";
            this.txtSearch.Size = new System.Drawing.Size(179, 22);
            this.txtSearch.TabIndex = 7;
            // 
            // cbbSort
            // 
            this.cbbSort.FormattingEnabled = true;
            this.cbbSort.Location = new System.Drawing.Point(146, 321);
            this.cbbSort.Name = "cbbSort";
            this.cbbSort.Size = new System.Drawing.Size(186, 24);
            this.cbbSort.TabIndex = 8;
            // 
            // STT
            // 
            this.STT.DataPropertyName = "STT";
            this.STT.HeaderText = "STT";
            this.STT.MinimumWidth = 6;
            this.STT.Name = "STT";
            this.STT.Width = 125;
            // 
            // MSP1
            // 
            this.MSP1.DataPropertyName = "MSP";
            this.MSP1.HeaderText = "Mã sản phẩm";
            this.MSP1.MinimumWidth = 6;
            this.MSP1.Name = "MSP1";
            this.MSP1.Width = 125;
            // 
            // TSP1
            // 
            this.TSP1.DataPropertyName = "TSP";
            this.TSP1.HeaderText = "Tên sản phẩm";
            this.TSP1.MinimumWidth = 6;
            this.TSP1.Name = "TSP1";
            this.TSP1.Width = 125;
            // 
            // SX1
            // 
            this.SX1.DataPropertyName = "SX";
            this.SX1.HeaderText = "Nhà SX";
            this.SX1.MinimumWidth = 6;
            this.SX1.Name = "SX1";
            this.SX1.Width = 125;
            // 
            // NN1
            // 
            this.NN1.DataPropertyName = "NN";
            this.NN1.HeaderText = "Ngày nhập";
            this.NN1.MinimumWidth = 6;
            this.NN1.Name = "NN1";
            this.NN1.Width = 125;
            // 
            // TMH1
            // 
            this.TMH1.DataPropertyName = "TMH";
            this.TMH1.HeaderText = "Mặt hàng";
            this.TMH1.MinimumWidth = 6;
            this.TMH1.Name = "TMH1";
            this.TMH1.Width = 125;
            // 
            // TT1
            // 
            this.TT1.DataPropertyName = "TT";
            this.TT1.HeaderText = "Tình trạng";
            this.TT1.MinimumWidth = 6;
            this.TT1.Name = "TT1";
            this.TT1.Width = 125;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1008, 372);
            this.Controls.Add(this.cbbSort);
            this.Controls.Add(this.txtSearch);
            this.Controls.Add(this.butSort);
            this.Controls.Add(this.butSearch);
            this.Controls.Add(this.butDelete);
            this.Controls.Add(this.butUpdate);
            this.Controls.Add(this.butAdd);
            this.Controls.Add(this.dataGridView1);
            this.Name = "MainForm";
            this.Text = "MainForm";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button butAdd;
        private System.Windows.Forms.Button butUpdate;
        private System.Windows.Forms.Button butDelete;
        private System.Windows.Forms.Button butSearch;
        private System.Windows.Forms.Button butSort;
        private System.Windows.Forms.TextBox txtSearch;
        private System.Windows.Forms.ComboBox cbbSort;
        private System.Windows.Forms.DataGridViewTextBoxColumn STT;
        private System.Windows.Forms.DataGridViewTextBoxColumn MSP1;
        private System.Windows.Forms.DataGridViewTextBoxColumn TSP1;
        private System.Windows.Forms.DataGridViewTextBoxColumn SX1;
        private System.Windows.Forms.DataGridViewTextBoxColumn NN1;
        private System.Windows.Forms.DataGridViewComboBoxColumn TMH1;
        private System.Windows.Forms.DataGridViewCheckBoxColumn TT1;
    }
}

