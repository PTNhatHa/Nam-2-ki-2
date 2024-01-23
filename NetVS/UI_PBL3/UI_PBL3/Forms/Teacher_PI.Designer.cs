namespace UI_PBL3.Forms
{
    partial class Teacher_PI
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
            this.buttonPI = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonPI
            // 
            this.buttonPI.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(235)))), ((int)(((byte)(69)))), ((int)(((byte)(95)))));
            this.buttonPI.Dock = System.Windows.Forms.DockStyle.Top;
            this.buttonPI.FlatAppearance.BorderSize = 0;
            this.buttonPI.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonPI.Font = new System.Drawing.Font("Palatino Linotype", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonPI.ForeColor = System.Drawing.Color.White;
            this.buttonPI.Image = global::UI_PBL3.Properties.Resources.icon1;
            this.buttonPI.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.buttonPI.Location = new System.Drawing.Point(0, 0);
            this.buttonPI.Name = "buttonPI";
            this.buttonPI.Padding = new System.Windows.Forms.Padding(10, 0, 0, 0);
            this.buttonPI.Size = new System.Drawing.Size(800, 81);
            this.buttonPI.TabIndex = 2;
            this.buttonPI.Text = " Personal Information";
            this.buttonPI.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.buttonPI.UseVisualStyleBackColor = false;
            // 
            // Teacher_PI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonPI);
            this.Name = "Teacher_PI";
            this.Text = "Teacher_PI";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonPI;
    }
}