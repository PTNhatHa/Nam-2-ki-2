namespace UI_PBL3.Forms
{
    partial class Teacher_Mark
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
            this.buttonMark = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonMark
            // 
            this.buttonMark.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(235)))), ((int)(((byte)(69)))), ((int)(((byte)(95)))));
            this.buttonMark.Dock = System.Windows.Forms.DockStyle.Top;
            this.buttonMark.FlatAppearance.BorderSize = 0;
            this.buttonMark.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonMark.Font = new System.Drawing.Font("Palatino Linotype", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonMark.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(253)))), ((int)(((byte)(244)))));
            this.buttonMark.Image = global::UI_PBL3.Properties.Resources.icon2;
            this.buttonMark.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.buttonMark.Location = new System.Drawing.Point(0, 0);
            this.buttonMark.Name = "buttonMark";
            this.buttonMark.Padding = new System.Windows.Forms.Padding(10, 0, 0, 0);
            this.buttonMark.Size = new System.Drawing.Size(800, 81);
            this.buttonMark.TabIndex = 3;
            this.buttonMark.Text = " Mark";
            this.buttonMark.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.buttonMark.UseVisualStyleBackColor = false;
            // 
            // Teacher_Mark
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonMark);
            this.Name = "Teacher_Mark";
            this.Text = "Teacher_Mark";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonMark;
    }
}