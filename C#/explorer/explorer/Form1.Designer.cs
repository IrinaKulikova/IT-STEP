namespace explorer
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
            this.treeViewExplorer = new System.Windows.Forms.TreeView();
            this.listViewExplorer = new System.Windows.Forms.ListView();
            this.comboBoxListView = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // treeViewExplorer
            // 
            this.treeViewExplorer.Dock = System.Windows.Forms.DockStyle.Left;
            this.treeViewExplorer.Location = new System.Drawing.Point(0, 0);
            this.treeViewExplorer.Name = "treeViewExplorer";
            this.treeViewExplorer.Size = new System.Drawing.Size(181, 561);
            this.treeViewExplorer.TabIndex = 0;
            this.treeViewExplorer.BeforeCollapse += new System.Windows.Forms.TreeViewCancelEventHandler(this.TreeViewExplorer_BeforeCollapse);
            this.treeViewExplorer.NodeMouseClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.TreeViewExplorer_NodeMouseClick);
            this.treeViewExplorer.NodeMouseDoubleClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.TreeViewExplorer_NodeMouseDoubleClick);
            // 
            // listViewExplorer
            // 
            this.listViewExplorer.AllowDrop = true;
            this.listViewExplorer.FullRowSelect = true;
            this.listViewExplorer.Location = new System.Drawing.Point(187, 27);
            this.listViewExplorer.Name = "listViewExplorer";
            this.listViewExplorer.Size = new System.Drawing.Size(597, 534);
            this.listViewExplorer.TabIndex = 1;
            this.listViewExplorer.UseCompatibleStateImageBehavior = false;
            this.listViewExplorer.DragDrop += new System.Windows.Forms.DragEventHandler(this.ListViewExplorer_DragDrop);
            this.listViewExplorer.DragEnter += new System.Windows.Forms.DragEventHandler(this.ListViewExplorer_DragEnter);
            this.listViewExplorer.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.ListViewExplorer_MouseDoubleClick);
            // 
            // comboBoxListView
            // 
            this.comboBoxListView.FormattingEnabled = true;
            this.comboBoxListView.Location = new System.Drawing.Point(187, 0);
            this.comboBoxListView.Name = "comboBoxListView";
            this.comboBoxListView.Size = new System.Drawing.Size(597, 21);
            this.comboBoxListView.TabIndex = 2;
            this.comboBoxListView.SelectedIndexChanged += new System.EventHandler(this.ComboBoxListView_SelectedIndexChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 561);
            this.Controls.Add(this.comboBoxListView);
            this.Controls.Add(this.listViewExplorer);
            this.Controls.Add(this.treeViewExplorer);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "Explorer";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TreeView treeViewExplorer;
        private System.Windows.Forms.ListView listViewExplorer;
        private System.Windows.Forms.ComboBox comboBoxListView;
    }
}

