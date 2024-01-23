namespace UI_PBL3
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
            this.PanelMenu = new System.Windows.Forms.Panel();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panelMain = new System.Windows.Forms.Panel();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.buttonSchedule = new System.Windows.Forms.Button();
            this.buttonMark = new System.Windows.Forms.Button();
            this.buttonPI = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.PanelMenu.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // PanelMenu
            // 
            this.PanelMenu.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(235)))), ((int)(((byte)(69)))), ((int)(((byte)(95)))));
            this.PanelMenu.Controls.Add(this.buttonSchedule);
            this.PanelMenu.Controls.Add(this.buttonMark);
            this.PanelMenu.Controls.Add(this.buttonPI);
            this.PanelMenu.Controls.Add(this.panel1);
            this.PanelMenu.Dock = System.Windows.Forms.DockStyle.Left;
            this.PanelMenu.Location = new System.Drawing.Point(0, 0);
            this.PanelMenu.Name = "PanelMenu";
            this.PanelMenu.Size = new System.Drawing.Size(386, 590);
            this.PanelMenu.TabIndex = 0;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.textBox1);
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(386, 217);
            this.panel1.TabIndex = 0;
            // 
            // panelMain
            // 
            this.panelMain.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelMain.Location = new System.Drawing.Point(386, 0);
            this.panelMain.Name = "panelMain";
            this.panelMain.Size = new System.Drawing.Size(725, 590);
            this.panelMain.TabIndex = 1;
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(235)))), ((int)(((byte)(69)))), ((int)(((byte)(95)))));
            this.textBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox1.CausesValidation = false;
            this.textBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox1.Enabled = false;
            this.textBox1.Font = new System.Drawing.Font("Palatino Linotype", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.ForeColor = System.Drawing.Color.Black;
            this.textBox1.Location = new System.Drawing.Point(0, 173);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(386, 34);
            this.textBox1.TabIndex = 1;
            this.textBox1.Text = "Username";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonSchedule
            // 
            this.buttonSchedule.Dock = System.Windows.Forms.DockStyle.Top;
            this.buttonSchedule.FlatAppearance.BorderSize = 0;
            this.buttonSchedule.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonSchedule.Font = new System.Drawing.Font("Palatino Linotype", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonSchedule.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(253)))), ((int)(((byte)(244)))));
            this.buttonSchedule.Image = global::UI_PBL3.Properties.Resources.icon3;
            this.buttonSchedule.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.buttonSchedule.Location = new System.Drawing.Point(0, 379);
            this.buttonSchedule.Name = "buttonSchedule";
            this.buttonSchedule.Padding = new System.Windows.Forms.Padding(10, 0, 0, 0);
            this.buttonSchedule.Size = new System.Drawing.Size(386, 81);
            this.buttonSchedule.TabIndex = 3;
            this.buttonSchedule.Text = " Schedule";
            this.buttonSchedule.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.buttonSchedule.UseVisualStyleBackColor = true;
            this.buttonSchedule.Click += new System.EventHandler(this.buttonSchedule_Click);
            // 
            // buttonMark
            // 
            this.buttonMark.Dock = System.Windows.Forms.DockStyle.Top;
            this.buttonMark.FlatAppearance.BorderSize = 0;
            this.buttonMark.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonMark.Font = new System.Drawing.Font("Palatino Linotype", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonMark.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(253)))), ((int)(((byte)(244)))));
            this.buttonMark.Image = global::UI_PBL3.Properties.Resources.icon2;
            this.buttonMark.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.buttonMark.Location = new System.Drawing.Point(0, 298);
            this.buttonMark.Name = "buttonMark";
            this.buttonMark.Padding = new System.Windows.Forms.Padding(10, 0, 0, 0);
            this.buttonMark.Size = new System.Drawing.Size(386, 81);
            this.buttonMark.TabIndex = 2;
            this.buttonMark.Text = " Mark";
            this.buttonMark.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.buttonMark.UseVisualStyleBackColor = true;
            this.buttonMark.Click += new System.EventHandler(this.buttonMark_Click);
            // 
            // buttonPI
            // 
            this.buttonPI.Dock = System.Windows.Forms.DockStyle.Top;
            this.buttonPI.FlatAppearance.BorderSize = 0;
            this.buttonPI.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonPI.Font = new System.Drawing.Font("Palatino Linotype", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonPI.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(253)))), ((int)(((byte)(244)))));
            this.buttonPI.Image = global::UI_PBL3.Properties.Resources.icon1;
            this.buttonPI.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.buttonPI.Location = new System.Drawing.Point(0, 217);
            this.buttonPI.Name = "buttonPI";
            this.buttonPI.Padding = new System.Windows.Forms.Padding(10, 0, 0, 0);
            this.buttonPI.Size = new System.Drawing.Size(386, 81);
            this.buttonPI.TabIndex = 1;
            this.buttonPI.Text = " Personal Information";
            this.buttonPI.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.buttonPI.UseVisualStyleBackColor = true;
            this.buttonPI.Click += new System.EventHandler(this.buttonPI_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.pictureBox1.Image = global::UI_PBL3.Properties.Resources.icon5;
            this.pictureBox1.Location = new System.Drawing.Point(0, 0);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(10);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(386, 173);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1111, 590);
            this.Controls.Add(this.panelMain);
            this.Controls.Add(this.PanelMenu);
            this.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "Form1";
            this.Text = "Form1";
            this.PanelMenu.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel PanelMenu;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button buttonPI;
        private System.Windows.Forms.Button buttonSchedule;
        private System.Windows.Forms.Button buttonMark;
        private System.Windows.Forms.Panel panelMain;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.TextBox textBox1;
    }
}

