namespace bt1Form
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
            this.Dental = new System.Windows.Forms.Label();
            this.Name = new System.Windows.Forms.Label();
            this.textName = new System.Windows.Forms.TextBox();
            this.caovoi = new System.Windows.Forms.CheckBox();
            this.taytrang = new System.Windows.Forms.CheckBox();
            this.chuphinhrang = new System.Windows.Forms.CheckBox();
            this.giacaovoi = new System.Windows.Forms.Label();
            this.giataytrang = new System.Windows.Forms.Label();
            this.giachuphinh = new System.Windows.Forms.Label();
            this.tramrang = new System.Windows.Forms.Label();
            this.slrang = new System.Windows.Forms.ComboBox();
            this.giatramrang = new System.Windows.Forms.Label();
            this.tong = new System.Windows.Forms.Label();
            this.txttong = new System.Windows.Forms.TextBox();
            this.thoat = new System.Windows.Forms.Button();
            this.tinhtien = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Dental
            // 
            this.Dental.AutoSize = true;
            this.Dental.Location = new System.Drawing.Point(170, 18);
            this.Dental.Name = "Dental";
            this.Dental.Size = new System.Drawing.Size(136, 16);
            this.Dental.TabIndex = 0;
            this.Dental.Text = "Dental Payment Form";
            // 
            // Name
            // 
            this.Name.AutoSize = true;
            this.Name.Location = new System.Drawing.Point(79, 67);
            this.Name.Name = "Name";
            this.Name.Size = new System.Drawing.Size(103, 16);
            this.Name.TabIndex = 1;
            this.Name.Text = "Tên khách hàng";
            // 
            // textName
            // 
            this.textName.Location = new System.Drawing.Point(233, 67);
            this.textName.Name = "textName";
            this.textName.Size = new System.Drawing.Size(166, 22);
            this.textName.TabIndex = 2;
            // 
            // caovoi
            // 
            this.caovoi.AutoSize = true;
            this.caovoi.Location = new System.Drawing.Point(82, 112);
            this.caovoi.Name = "caovoi";
            this.caovoi.Size = new System.Drawing.Size(75, 20);
            this.caovoi.TabIndex = 3;
            this.caovoi.Text = "Cạo vôi";
            this.caovoi.UseVisualStyleBackColor = true;
            // 
            // taytrang
            // 
            this.taytrang.AutoSize = true;
            this.taytrang.Location = new System.Drawing.Point(82, 156);
            this.taytrang.Name = "taytrang";
            this.taytrang.Size = new System.Drawing.Size(86, 20);
            this.taytrang.TabIndex = 4;
            this.taytrang.Text = "Tẩy trắng";
            this.taytrang.UseVisualStyleBackColor = true;
            // 
            // chuphinhrang
            // 
            this.chuphinhrang.AutoSize = true;
            this.chuphinhrang.Location = new System.Drawing.Point(82, 202);
            this.chuphinhrang.Name = "chuphinhrang";
            this.chuphinhrang.Size = new System.Drawing.Size(117, 20);
            this.chuphinhrang.TabIndex = 5;
            this.chuphinhrang.Text = "Chụp hình răng";
            this.chuphinhrang.UseVisualStyleBackColor = true;
            // 
            // giacaovoi
            // 
            this.giacaovoi.AutoSize = true;
            this.giacaovoi.Location = new System.Drawing.Point(353, 112);
            this.giacaovoi.Name = "giacaovoi";
            this.giacaovoi.Size = new System.Drawing.Size(59, 16);
            this.giacaovoi.TabIndex = 6;
            this.giacaovoi.Text = "$100.000";
            // 
            // giataytrang
            // 
            this.giataytrang.AutoSize = true;
            this.giataytrang.Location = new System.Drawing.Point(343, 156);
            this.giataytrang.Name = "giataytrang";
            this.giataytrang.Size = new System.Drawing.Size(69, 16);
            this.giataytrang.TabIndex = 7;
            this.giataytrang.Text = "$1.200.000";
            // 
            // giachuphinh
            // 
            this.giachuphinh.AutoSize = true;
            this.giachuphinh.Location = new System.Drawing.Point(353, 202);
            this.giachuphinh.Name = "giachuphinh";
            this.giachuphinh.Size = new System.Drawing.Size(59, 16);
            this.giachuphinh.TabIndex = 8;
            this.giachuphinh.Text = "$200.000";
            // 
            // tramrang
            // 
            this.tramrang.AutoSize = true;
            this.tramrang.Location = new System.Drawing.Point(79, 258);
            this.tramrang.Name = "tramrang";
            this.tramrang.Size = new System.Drawing.Size(75, 16);
            this.tramrang.TabIndex = 9;
            this.tramrang.Text = "Trám Răng";
            // 
            // slrang
            // 
            this.slrang.FormattingEnabled = true;
            this.slrang.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5"});
            this.slrang.Location = new System.Drawing.Point(173, 258);
            this.slrang.Name = "slrang";
            this.slrang.Size = new System.Drawing.Size(121, 24);
            this.slrang.TabIndex = 10;
            // 
            // giatramrang
            // 
            this.giatramrang.AutoSize = true;
            this.giatramrang.Location = new System.Drawing.Point(338, 261);
            this.giatramrang.Name = "giatramrang";
            this.giatramrang.Size = new System.Drawing.Size(74, 16);
            this.giatramrang.TabIndex = 11;
            this.giatramrang.Text = "$80.000/cái";
            // 
            // tong
            // 
            this.tong.AutoSize = true;
            this.tong.Location = new System.Drawing.Point(256, 332);
            this.tong.Name = "tong";
            this.tong.Size = new System.Drawing.Size(38, 16);
            this.tong.TabIndex = 12;
            this.tong.Text = "Total";
            // 
            // txttong
            // 
            this.txttong.Location = new System.Drawing.Point(312, 329);
            this.txttong.Name = "txttong";
            this.txttong.Size = new System.Drawing.Size(100, 22);
            this.txttong.TabIndex = 13;
            // 
            // thoat
            // 
            this.thoat.Location = new System.Drawing.Point(107, 364);
            this.thoat.Name = "thoat";
            this.thoat.Size = new System.Drawing.Size(75, 23);
            this.thoat.TabIndex = 14;
            this.thoat.Text = "Thoát";
            this.thoat.UseVisualStyleBackColor = true;
            this.thoat.Click += new System.EventHandler(this.thoat_Click);
            // 
            // tinhtien
            // 
            this.tinhtien.Location = new System.Drawing.Point(266, 364);
            this.tinhtien.Name = "tinhtien";
            this.tinhtien.Size = new System.Drawing.Size(75, 23);
            this.tinhtien.TabIndex = 15;
            this.tinhtien.Text = "Tính tiền";
            this.tinhtien.UseVisualStyleBackColor = true;
            this.tinhtien.Click += new System.EventHandler(this.tinhtien_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(494, 450);
            this.Controls.Add(this.tinhtien);
            this.Controls.Add(this.thoat);
            this.Controls.Add(this.txttong);
            this.Controls.Add(this.tong);
            this.Controls.Add(this.giatramrang);
            this.Controls.Add(this.slrang);
            this.Controls.Add(this.tramrang);
            this.Controls.Add(this.giachuphinh);
            this.Controls.Add(this.giataytrang);
            this.Controls.Add(this.giacaovoi);
            this.Controls.Add(this.chuphinhrang);
            this.Controls.Add(this.taytrang);
            this.Controls.Add(this.caovoi);
            this.Controls.Add(this.textName);
            this.Controls.Add(this.Name);
            this.Controls.Add(this.Dental);
            this.Name = "Form1";
            this.Text = "Dental Payment Application";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Dental;
        private System.Windows.Forms.Label Name;
        private System.Windows.Forms.TextBox textName;
        private System.Windows.Forms.CheckBox caovoi;
        private System.Windows.Forms.CheckBox taytrang;
        private System.Windows.Forms.CheckBox chuphinhrang;
        private System.Windows.Forms.Label giacaovoi;
        private System.Windows.Forms.Label giataytrang;
        private System.Windows.Forms.Label giachuphinh;
        private System.Windows.Forms.Label tramrang;
        private System.Windows.Forms.ComboBox slrang;
        private System.Windows.Forms.Label giatramrang;
        private System.Windows.Forms.Label tong;
        private System.Windows.Forms.TextBox txttong;
        private System.Windows.Forms.Button thoat;
        private System.Windows.Forms.Button tinhtien;
    }
}

