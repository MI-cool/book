/*
 * ImagePanel.java
 *
 * Created on March 15, 2005, 2:34 PM
 */

import java.awt.*;
import java.util.*;

/**
 *
 * @author  cmlee
 */
public class ImagePanel extends javax.swing.JPanel {
    
    protected Hashtable<String, Image> cache;
    protected Image currImage = null;
    
    /** Creates new form ImagePanel */
    public ImagePanel() {
        cache = new Hashtable<String, Image>();
        initComponents();
    }
    
    public void setImage(String fn) {
	if ((fn == null) || (fn.length() <= 0))
	    return;
        
        if (cache.containsKey(fn))
            currImage = cache.get(fn);
        else {
            Toolkit toolkit = Toolkit.getDefaultToolkit();
            currImage = toolkit.createImage(fn);
            cache.put(fn, currImage);
        }
        
        repaint();
    }    
    
    public Dimension getPreferredSize() {
        if (currImage == null)
            return (super.getPreferredSize());
      
        return (new Dimension(currImage.getWidth(this), currImage.getHeight(this)));
    }
    
    public void paint(Graphics g) {
        if (currImage == null) {            
            g.setColor(Color.BLACK);
            g.drawString("No image", 10, 50);
        }

	g.setColor(Color.BLACK);
	g.fillRect(0, 0, this.getWidth(), this.getHeight());

        g.drawImage(currImage, 0, 0, this);
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    private void initComponents() {//GEN-BEGIN:initComponents
        
        setLayout(new java.awt.BorderLayout());
        
    }//GEN-END:initComponents
    
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
    
}
