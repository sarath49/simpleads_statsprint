<?php
/**
 * References dompdf namespace.
 */
use Dompdf\Dompdf;

/**
 * Performs print operation when link is clicked.
 */
function simpleads_statsprint_pdf($nodeid) {
  if($nodeid == $_SESSION['simpleads_statsprint']['nid']) {
    $markup = $_SESSION['simpleads_statsprint']['markup'];
    _simpleads_statsprint_data($nodeid);
    // instantiate and use the dompdf class
    $dompdf = new Dompdf();
    
    $dompdf->loadHtml($markup);

    // (Optional) Setup the paper size and orientation
    $dompdf->setPaper('A4', 'portrait');

    // Render the HTML as PDF
    $dompdf->render();

    // Output the generated PDF to Browser
    $dompdf->stream();
     
    //return;
  }
  
 // unset($_SESSION['simpleads_statsprint']);
 // return;
}

/**
 * 
 * @param type $nodeid
 * @return type string'
 *   A string contaning html markup to be generated as pdf.
 */
function _simpleads_statsprint_data($nodeid) {
  
  $fields = array(
    'date', 'clicks', 'clicks_unique', 'impressions', 'impressions_unique'
  );
  $query = db_select('simpleads_stats', 's');
  $query->fields('s', $fields)
      ->condition('s.nid', $nodeid, '=');
  $result = $query->execute()->fetchAll();
  dpm($result);
  return $markup;
}