/*
 * ImageManager.java
 *
 * Created on June 3, 2005, 12:28 PM
 */

package j1viewer;

import java.awt.*;
import java.awt.event.*;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.*;

/**
 *
 * @author  cmlee
 */
public class ImageManager extends javax.swing.JFrame
        implements ListSelectionListener, ItemListener, ChangeListener {
    
    private File imageDirectory = null;
    private int scale;
    
    /** Creates new form ImageManager */
    public ImageManager() {
        initComponents();
        jTable1.getColumnModel().getSelectionModel().addListSelectionListener(this);
        jTable1.getSelectionModel().addListSelectionListener(this);
        jRadioButton1.addItemListener(this);
        
        Hashtable<Integer, JLabel> label = new Hashtable<Integer, JLabel>();
        label.put(0, new JLabel("65x65"));
        label.put(1, new JLabel("90x90"));
        label.put(2, new JLabel("115x115"));
        label.put(3, new JLabel("140x140"));
        jSlider1.setLabelTable(label);
        jSlider1.addChangeListener(this);
        scale = getScale(jSlider1.getValue());
        
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
        buttonGroup1 = new javax.swing.ButtonGroup();
        jSplitPane1 = new javax.swing.JSplitPane();
        jPanel1 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jPanel2 = new javax.swing.JPanel();
        jRadioButton1 = new javax.swing.JRadioButton();
        jRadioButton2 = new javax.swing.JRadioButton();
        jPanel3 = new javax.swing.JPanel();
        jSlider1 = new javax.swing.JSlider();
        jSplitPane2 = new javax.swing.JSplitPane();
        jScrollPane2 = new javax.swing.JScrollPane();
        imagePanel1 = new j1viewer.ImagePanel();
        metadataPanel1 = new j1viewer.MetadataPanel();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();
        jMenuItem3 = new javax.swing.JMenuItem();
        jSeparator1 = new javax.swing.JSeparator();
        jMenuItem2 = new javax.swing.JMenuItem();

        jFileChooser1.setFileSelectionMode(javax.swing.JFileChooser.DIRECTORIES_ONLY);

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        jSplitPane1.setOneTouchExpandable(true);
        jPanel1.setLayout(new java.awt.BorderLayout());

        jTable1.setModel(new ImagesTableModel());
        jTable1.setCellSelectionEnabled(true);
        jScrollPane1.setViewportView(jTable1);

        jPanel1.add(jScrollPane1, java.awt.BorderLayout.CENTER);

        jPanel2.setLayout(new java.awt.GridLayout(1, 2, 3, 3));

        jPanel2.setBorder(new javax.swing.border.TitledBorder("Views"));
        buttonGroup1.add(jRadioButton1);
        jRadioButton1.setSelected(true);
        jRadioButton1.setText("Thumbnail");
        jPanel2.add(jRadioButton1);

        buttonGroup1.add(jRadioButton2);
        jRadioButton2.setText("Filename");
        jPanel2.add(jRadioButton2);

        jPanel1.add(jPanel2, java.awt.BorderLayout.NORTH);

        jPanel3.setLayout(new java.awt.BorderLayout());

        jPanel3.setBorder(new javax.swing.border.TitledBorder("Scale"));
        jSlider1.setMajorTickSpacing(1);
        jSlider1.setMaximum(3);
        jSlider1.setPaintLabels(true);
        jSlider1.setPaintTicks(true);
        jSlider1.setSnapToTicks(true);
        jSlider1.setValue(1);
        jPanel3.add(jSlider1, java.awt.BorderLayout.NORTH);

        jPanel1.add(jPanel3, java.awt.BorderLayout.SOUTH);

        jSplitPane1.setLeftComponent(jPanel1);

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

        jMenuItem3.setText("Change Skin...");
        jMenuItem3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem3ActionPerformed(evt);
            }
        });

        jMenu1.add(jMenuItem3);

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
    
    private void jMenuItem3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem3ActionPerformed
// TODO add your handling code here:
        //this refers to MyImageManager which is a JFrame
        ThemeSelectionBean themeSelection = new ThemeSelectionBean(this);
        
//Change <LAB_ROOT> to the actual lab directory
        themeSelection.setSkinFolder("<LAB_ROOT>/resources/themepacks");
        
//display it
        themeSelection.setVisible(true);
    }//GEN-LAST:event_jMenuItem3ActionPerformed
    
    private void jMenuItem2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem2ActionPerformed
// TODO add your handling code here:
        setVisible(false);
        dispose();
        System.exit(0);
    }//GEN-LAST:event_jMenuItem2ActionPerformed
    
    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
// TODO add your handling code here:
        if (jFileChooser1.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
            imageDirectory = jFileChooser1.getSelectedFile();
            setupModel();
        }
    }//GEN-LAST:event_jMenuItem1ActionPerformed
    
    private void setTableCellSize(int thumbnailSize) {
        jTable1.setRowHeight(thumbnailSize + 10);
        TableModel model = jTable1.getModel();
        TableColumnModel tableColumnModel = jTable1.getColumnModel();
        for (int i = 0; i < model.getColumnCount(); i++)
            tableColumnModel.getColumn(i).setPreferredWidth(thumbnailSize + 10);
    }
    
    public void stateChanged(ChangeEvent cEvt) {             
        
        ImagesTableModel model;
        
        if (jSlider1.getValueIsAdjusting())
            return;               
        
        //Check if the current selected image scale is the same
        //as what we have
        scale = getScale(jSlider1.getValue());
        model = (ImagesTableModel)jTable1.getModel();
        if (scale == model.getThumbnailScale())
            return;
        
        setupModel();
    }
    
    public void itemStateChanged(ItemEvent iEvt) {
        
        jSlider1.setEnabled(jRadioButton1.isSelected());        
        
        setupModel();
    }
    
    private void setupModel() {
        
        if (imageDirectory == null)
            return;
        
        if (jRadioButton1.isSelected()) {
            ImagesTableModel model = new ImagesTableModel(imageDirectory.getAbsolutePath(), scale);
            jTable1.setModel(model);
            jTable1.setDefaultRenderer(ImagesTableModel._ImageTablePanel.class, model);
            setTableCellSize(ImagesTableModel.THUMBNAIL_SIZE);
            return;
        }
        
        ImageNamesTableModel model = new ImageNamesTableModel(imageDirectory.getAbsolutePath());
        jTable1.setModel(model);
        jTable1.setDefaultRenderer(ImageNamesTableModel.TableImagePanel.class, model);
        ImageNamesTableModel.TableImagePanel p = (ImageNamesTableModel.TableImagePanel)model.getValueAt(0, 0);
        jTable1.setRowHeight((int)p.getPreferredSize().getHeight());
    }
    
    public void valueChanged(ListSelectionEvent lsEvt) {
        
        String imageName;
        
        //Get the selected row and column
        int row = jTable1.getSelectedRow();
        int col = jTable1.getSelectedColumn();
        if ((row <= -1) || (col <= -1))
            return;
        
        //Need to discriminate what model are we using
        if (jRadioButton1.isSelected()) {
            ImagesTableModel model = (ImagesTableModel)jTable1.getModel();
            imageName = model.getImageName(row, col);
        } else {
            ImageNamesTableModel model = (ImageNamesTableModel)jTable1.getModel();
            imageName = model.getImageName(row, col);
        }
        
        
        //Get the selected image file name from the model and pass this to
        //ImagePanel. ImagePanel will then load the image
        imagePanel1.setImage(imageName);
        jScrollPane2.setPreferredSize(imagePanel1.getPreferredSize());
        jScrollPane2.doLayout();
        
        setTitle("MyImageManager:" + imageName);
    }
    
    private int getScale(int i) {
        
        switch (i) {
            case 0:
                return (65);
                
            default:
            case 1:
                return (90);
                
            case 2:
                return (115);
                
            case 3:
                return (140);
        }
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
    private javax.swing.ButtonGroup buttonGroup1;
    private j1viewer.ImagePanel imagePanel1;
    private javax.swing.JFileChooser jFileChooser1;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem2;
    private javax.swing.JMenuItem jMenuItem3;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JRadioButton jRadioButton1;
    private javax.swing.JRadioButton jRadioButton2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JSlider jSlider1;
    private javax.swing.JSplitPane jSplitPane1;
    private javax.swing.JSplitPane jSplitPane2;
    private javax.swing.JTable jTable1;
    private j1viewer.MetadataPanel metadataPanel1;
    // End of variables declaration//GEN-END:variables
    
}
