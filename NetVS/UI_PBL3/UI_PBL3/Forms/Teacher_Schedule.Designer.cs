namespace UI_PBL3.Forms
{
    partial class Teacher_Schedule
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
            this.buttonSchedule = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonSchedule
            // 
            this.buttonSchedule.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(235)))), ((int)(((byte)(69)))), ((int)(((byte)(95)))));
            this.buttonSchedule.Dock = System.Windows.Forms.DockStyle.Top;
            this.buttonSchedule.FlatAppearance.BorderSize = 0;
            this.buttonSchedule.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonSchedule.Font = new System.Drawing.Font("Palatino Linotype", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonSchedule.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(252)))), ((int)(((byte)(253)))), ((int)(((byte)(244)))));
            this.buttonSchedule.Image = global::UI_PBL3.Properties.Resources.icon3;
            this.buttonSchedule.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.buttonSchedule.Location = new System.Drawing.Point(0, 0);
            this.buttonSchedule.Name = "buttonSchedule";
            this.buttonSchedule.Padding = new System.Windows.Forms.Padding(10, 0, 0, 0);
            this.buttonSchedule.Size = new System.Drawing.Size(800, 81);
            this.buttonSchedule.TabIndex = 4;
            this.buttonSchedule.Text = " Schedule";
            this.buttonSchedule.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.buttonSchedule.UseVisualStyleBackColor = false;
            // 
            // Teacher_Schedule
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonSchedule);
            this.Name = "Teacher_Schedule";
            this.Text = "Teacher_Schedule";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonSchedule;
    }
}