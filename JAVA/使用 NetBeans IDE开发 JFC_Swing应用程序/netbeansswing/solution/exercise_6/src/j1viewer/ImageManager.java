/*
 * ImageManager.java
 *
 * Created on June 3, 2005, 12:28 PM
 */

package j1viewer;

import java.io.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.*;

/**
 *
 * @author  cmlee
 */
public class ImageManager extends javax.swing.JFrame
        implements ListSelectionListener {
    
    /** Creates new form ImageManager */
    public ImageManager() {
        initComponents();
        jTable1.getColumnModel().getSelectionModel().addListSelectionListener(this);
        jTable1.getSelectionModel().addListSelectionListener(this);
        setTitle("MyImageManager");
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc=" Generated Code ">//GEN-BEGIN:initComponents
    private void initComponents() {
        jFileChooser1 = new javax.swing.JFileChooser();
        jSplitPane1 = new javax.swing.JSplitPane();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jSplitPane2 = new javax.swing.JSplitPane();
        jScrollPane2 = new javax.swing.JScrollPane();
        imagePanel1 = new j1viewer.ImagePanel();
        metadataPanel1 = new j1viewer.MetadataPanel();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();
        jSeparator1 = new javax.swing.JSeparator();
        jMenuItem2 = new javax.swing.JMenuItem();

        jFileChooser1.setFileSelectionMode(javax.swing.JFileChooser.DIRECTORIES_ONLY);

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        jSplitPane1.setOneTouchExpandable(true);
        jTable1.setModel(new ImagesTableModel());
        jTable1.setCellSelectionEnabled(true);
        jScrollPane1.setViewportView(jTable1);

        jSplitPane1.setLeftComponent(jScrollPane1);

        jSplitPane2.setOrientation(javax.swing.JSplitPane.VERTICAL_SPLIT);
        jSplitPane2.setOneTouchExpandable(true);
        jScrollPane2.setViewportView(imagePanel1);

        jSplitPane2.setLeftComponent(jScrollPane2);

        jSplitPane2.setRightComponent(metadataPanel1);

        jSplitPane1.setRightComponent(jSplitPane2);

        getContentPane().add(jSplitPane1, java.awt.BorderLayout.CENTER);

        jMenu1.setText("Menu");
        jMenuItem1.setLabel("Open...");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });

        jMenu1.add(jMenuItem1);

        jMenu1.add(jSeparator1);

        jMenuItem2.setLabel("Exit");
        jMenuItem2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem2ActionPerformed(evt);
            }
        });

        jMenu1.add(jMenuItem2);

        jMenuBar1.add(jMenu1);

        setJMenuBar(jMenuBar1);

        pack();
    }
    // </editor-fold>//GEN-END:initComponents
    
    private void jMenuItem2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem2ActionPerformed
// TODO add your handling code here:
        setVisible(false);
        dispose();
        System.exit(0);
    }//GEN-LAST:event_jMenuItem2ActionPerformed
    
    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
// TODO add your handling code here:
        if (jFileChooser1.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
            File f = jFileChooser1.getSelectedFile();
            ImagesTableModel model = new ImagesTableModel(f.getAbsolutePath());
            jTable1.setModel(model);
            jTable1.setDefaultRenderer(ImagesTableModel._ImageTablePanel.class, model);
            setTableCellSize(ImagesTableModel.THUMBNAIL_SIZE);
        }
    }//GEN-LAST:event_jMenuItem1ActionPerformed
    
    private void setTableCellSize(int thumbnailSize) {
        jTable1.setRowHeight(thumbnailSize + 10);
        TableModel model = jTable1.getModel();
        TableColumnModel tableColumnModel = jTable1.getColumnModel();
        for (int i = 0; i < model.getColumnCount(); i++)
            tableColumnModel.getColumn(i).setPreferredWidth(thumbnailSize + 10);
    }
    
    public void valueChanged(ListSelectionEvent lsEvt) {
        //Get the selected row and column
        int row = jTable1.getSelectedRow();
        int col = jTable1.getSelectedColumn();
        if ((row <= -1) || (col <= -1))
            return;
        
        //Get the table model
        ImagesTableModel model = (ImagesTableModel)jTable1.getModel();
        
        //Get the selected image file name from the model and pass this to
        //ImagePanel. ImagePanel will then load the image
        imagePanel1.setImage(model.getImageName(row, col));
        jScrollPane2.setPreferredSize(imagePanel1.getPreferredSize());
        jScrollPane2.doLayout();
        
        setTitle("MyImageManager:" + model.getImageName(row, col));
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ImageManager().setVisible(true);
            }
        });
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private j1viewer.ImagePanel imagePanel1;
    private javax.swing.JFileChooser jFileChooser1;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JSplitPane jSplitPane1;
    private javax.swing.JSplitPane jSplitPane2;
    private javax.swing.JTable jTable1;
    private j1viewer.MetadataPanel metadataPanel1;
    // End of variables declaration//GEN-END:variables
    
}
