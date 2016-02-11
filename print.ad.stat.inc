<?php
/**
 * References dompdf namespace.
 */
use Dompdf\Dompdf;

/**
 * Performs print operation when link is clicked.
 */
function simpleads_stats_pdf($nodeid) {
  if($nodeid == $_SESSION['simpleads_statsprint']['nid']) {
    $markup = $_SESSION['simpleads_statsprint']['markup'];

    // instantiate and use the dompdf class
    $dompdf = new Dompdf();
    
    $dompdf->loadHtml($markup);

    // (Optional) Setup the paper size and orientation
    $dompdf->setPaper('A4', 'landscape');

    // Render the HTML as PDF
    $dompdf->render();

    // Output the generated PDF to Browser
    $dompdf->stream();
     
    return;
  }
  
  unset($_SESSION['simpleads_statsprint']);
  return;
}