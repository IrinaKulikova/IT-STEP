using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace explorer
{
    /// <summary>
    /// главное окно приложения
    /// </summary>
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        /// <summary>
        /// обработка загрузки приложения
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_Load(object sender, EventArgs e)
        {
            //подписываемся на событие перед раскрытием
            treeViewExplorer.BeforeExpand += TreeViewExplorer_BeforeExpand;

            //получаем список всех дисков в системе
            DriveInfo[] allDrives = DriveInfo.GetDrives();

            foreach (DriveInfo d in allDrives)//перебираем диски и создаём узлы
            {
                TreeNode node = new TreeNode(d.Name)
                {
                    SelectedImageIndex = 0,
                    ImageIndex = 0
                };
                node.Nodes.Add(new TreeNode("Fake Node"));
                treeViewExplorer.Nodes.Add(node);
            }

            int sizeBigIcons = 32;
            int sizeSmallIcons = 16;

            //создаём список картинок
            ImageList imageList = new ImageList();
            ImageList largeImages = new ImageList();
            ImageList smallImages = new ImageList();
            largeImages.ImageSize = new Size(sizeBigIcons, sizeBigIcons);

            //закрытая папка
            string folderClose = Path.Combine("icons", "folder-closed-icon.png");
            if (File.Exists(folderClose))
            {
                imageList.Images.Add(Image.FromFile(folderClose));
                smallImages.Images.Add(Image.FromFile(folderClose));
                largeImages.Images.Add(Image.FromFile(folderClose));
            }

            //открытая папка
            string folderOpen = Path.Combine("icons", "folder-open-icon.png");
            if (File.Exists(folderOpen))
            {
                imageList.Images.Add(Image.FromFile(folderOpen));
                smallImages.Images.Add(Image.FromFile(folderOpen));
                largeImages.Images.Add(Image.FromFile(folderOpen));
            }

            //иконка фаила
            string file = Path.Combine("icons", "file-icon.png");
            if (File.Exists(file))
            {
                imageList.Images.Add(Image.FromFile(file));
                smallImages.Images.Add(Image.FromFile(file));
                largeImages.Images.Add(Image.FromFile(file));
            }

            //настроийки иконок
            imageList.ColorDepth = ColorDepth.Depth24Bit;
            imageList.ImageSize = new Size(sizeSmallIcons, sizeSmallIcons);

            //назначаем лист картинок
            treeViewExplorer.ImageList = imageList;

            comboBoxListView.DataSource = Enum.GetNames(typeof(View));
            listViewExplorer.LargeImageList = largeImages;
            listViewExplorer.SmallImageList = smallImages;
            TreeViewExplorer_NodeMouseClick(null, new TreeNodeMouseClickEventArgs(treeViewExplorer.Nodes[0], MouseButtons.Left, 0, 0, 0));

            ColumnHeader firstColumn = new ColumnHeader
            {
                Text = "Folders and files"
            };

            ColumnHeader secondColumn = new ColumnHeader
            {
                Text = "Information"
            };

            ColumnHeader pathColumn = new ColumnHeader
            {
                Text = "FullPath"
            };

            listViewExplorer.Columns.Add(firstColumn);
            listViewExplorer.Columns.Add(secondColumn);
            listViewExplorer.Columns.Add(pathColumn);
        }

        /// <summary>
        /// обработка события перед раскрытием
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void TreeViewExplorer_BeforeExpand(object sender, TreeViewCancelEventArgs e)
        {
            e.Node.Nodes.Clear();//удаляем фэйковый узел

            //назначаем картинки
            e.Node.ImageIndex = 1;
            e.Node.SelectedImageIndex = 1;

            //назначаем выбранный узел
            if (e.Node.Parent != null)
            {
                e.Node.Parent.ImageIndex = 1;
            }
            else if (e.Node.FirstNode != null)
            {
                treeViewExplorer.SelectedNode = e.Node.FirstNode;
            }
            else if (e.Node.PrevNode != null)
            {
                treeViewExplorer.SelectedNode = e.Node.PrevNode;
            }
            else
            {
                treeViewExplorer.SelectedNode = e.Node.Parent;
            }

            //путь текущей папки
            string currentDirectory = e.Node.FullPath;

            try
            {
                //получаем вложенные папки

                string[] subdirectoryEntries = Directory.GetDirectories(currentDirectory);
                foreach (string subdirectory in subdirectoryEntries)
                {
                    string nameDirectiry = subdirectory.Replace(currentDirectory, "");
                    nameDirectiry = nameDirectiry.Replace("\\", "");
                    TreeNode subDirectoryNode = new TreeNode(nameDirectiry);
                    subDirectoryNode.Nodes.Add(new TreeNode("Fake Node"));
                    e.Node.Nodes.Add(subDirectoryNode);
                    subDirectoryNode.SelectedImageIndex = 0;
                    subDirectoryNode.ImageIndex = 0;
                }

                //получаем вложенный файлы
                string[] fileEntries = Directory.GetFiles(currentDirectory);
                foreach (string fileName in fileEntries)
                {
                    string nameFile = fileName.Replace(currentDirectory, "");
                    nameFile = nameFile.Replace("\\", "");
                    TreeNode childNode = new TreeNode(nameFile);
                    e.Node.Nodes.Add(childNode);
                    childNode.SelectedImageIndex = 2;
                    childNode.ImageIndex = 2;
                }
            }
            catch (Exception exception)//отлавливаем все исключения
            {
                MessageBox.Show(exception.Message, "error", MessageBoxButtons.OK);
            }
        }

        /// <summary>
        /// обработка события перед сварачиванием узла
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void TreeViewExplorer_BeforeCollapse(object sender, TreeViewCancelEventArgs e)
        {
            e.Node.ImageIndex = 0;
            treeViewExplorer.SelectedNode = e.Node.Parent;
        }

        /// <summary>
        /// обработка события двойного клика по узлу дерева
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void TreeViewExplorer_NodeMouseDoubleClick(object sender, TreeNodeMouseClickEventArgs e)
        {
            if (File.Exists(e.Node.FullPath))//если это фаил
            {
                System.Diagnostics.Process.Start(e.Node.FullPath);//открываем в программе по умолчанию
            }
        }

        /// <summary>
        /// клик по узлу treeview
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void TreeViewExplorer_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
        {
            listViewExplorer.Items.Clear();
            string currentDirectory = e.Node.FullPath;

            if (File.Exists(currentDirectory))//если это фаил
            {
                return;
            }

            //отображаем в listview все вложенные элементы
            GetDirectopyAndFiles(currentDirectory);
        }

        /// <summary>
        /// событие изминения в комбобоксе item
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ComboBoxListView_SelectedIndexChanged(object sender, EventArgs e)
        {
            listViewExplorer.View = (View)Enum.Parse(typeof(View), comboBoxListView.SelectedItem.ToString());
            listViewExplorer.Columns[0].AutoResize(ColumnHeaderAutoResizeStyle.ColumnContent);
            listViewExplorer.Columns[1].AutoResize(ColumnHeaderAutoResizeStyle.HeaderSize);
            listViewExplorer.Columns[2].AutoResize(ColumnHeaderAutoResizeStyle.ColumnContent);

        }

        /// <summary>
        /// обработка события закидывания данных
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ListViewExplorer_DragDrop(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))//если добавлены фаилы
            {
                string[] files = e.Data.GetData(DataFormats.FileDrop) as string[];

                foreach (string file in files)//перебираем данные и добавляем в лист
                {
                    listViewExplorer.Items.Add(Path.GetFileName(file), 2);
                }
            }
        }

        /// <summary>
        /// обработка события, курсор входит в контрал для которого задано свойство AllowDrop
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ListViewExplorer_DragEnter(object sender, DragEventArgs e)
        {
            e.Effect = DragDropEffects.Copy;
        }


        /// <summary>
        ///  обработка события двойного клика в элементе listview
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ListViewExplorer_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            if (listViewExplorer.SelectedItems != null)
            {
                string currentDirectory = listViewExplorer.SelectedItems[0].SubItems[2].Text;

                if (File.Exists(currentDirectory))//если это фаил
                {
                    System.Diagnostics.Process.Start(currentDirectory);//открываем в программе по умолчанию
                    return;
                }

                listViewExplorer.Items.Clear();

                //отображаем в listview все вложенные элементы
                GetDirectopyAndFiles(currentDirectory);
            }
        }

        /// <summary>
        /// получаем и отображаем вложенные элементы
        /// </summary>
        /// <param name="currentDirectory"></param>
        /// <param name="subdirectoryEntries"></param>
        private void GetDirectopyAndFiles(string currentDirectory)
        {
            ListViewItem.ListViewSubItem[] subItems;// сохраняем дополнительную информацию        

            try
            {
                //получаем вложенные папки                   
                string[] subdirectoryEntries = Directory.GetDirectories(currentDirectory);
                foreach (string subdirectory in subdirectoryEntries)
                {
                    string nameDirectiry = subdirectory.Replace(currentDirectory, "");
                    nameDirectiry = nameDirectiry.Replace("\\", "");
                    ListViewItem subDirectoryItem = new ListViewItem(nameDirectiry);
                    subItems = new ListViewItem.ListViewSubItem[] { new ListViewItem.ListViewSubItem(subDirectoryItem, "Directory"),
                                                                        new ListViewItem.ListViewSubItem(subDirectoryItem,currentDirectory+"\\"+nameDirectiry+"\\") };
                    subDirectoryItem.SubItems.AddRange(subItems);
                    listViewExplorer.Items.Add(subDirectoryItem);
                    subDirectoryItem.ImageIndex = 0;
                }

                //получаем вложенный файлы
                string[] fileEntries = Directory.GetFiles(currentDirectory);
                foreach (string fileName in fileEntries)
                {
                    string nameFile = fileName.Replace(currentDirectory, "");
                    nameFile = nameFile.Replace("\\", "");
                    ListViewItem childItem = new ListViewItem(nameFile);
                    subItems = new ListViewItem.ListViewSubItem[] { new ListViewItem.ListViewSubItem(childItem, "File"),
                                                                        new ListViewItem.ListViewSubItem(childItem, currentDirectory + "\\" + nameFile)};
                    childItem.SubItems.AddRange(subItems);
                    listViewExplorer.Items.Add(childItem);
                    childItem.ImageIndex = 2;
                }
            }
            catch (Exception exception)//отлавливаем все исключения
            {
                MessageBox.Show(exception.Message, "error", MessageBoxButtons.OK);
            }
        }
    }
}
