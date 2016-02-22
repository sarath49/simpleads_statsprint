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
    return _simpleads_statsprint_data($nodeid);
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
  
  unset($_SESSION['simpleads_statsprint']);
  return;
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
  $index = count($result);
  $total_data = array(
    'click' => 0, 
    'unique_clicks' => 0,
    'impressions' => 0,
    'unique_impressions' => 0,
    );
  
  $daily_stat = array();
  dpm($result);
  for ($i = 0; $i < $index; $i++) {
    $total_data['click'] += $result[$i]->clicks;
    $total_data['unique_clicks'] += $result[$i]->clicks_unique;
    $total_data['impressions'] += $result[$i]->impressions;
    $total_data['unique_impressions'] += $result[$i]->impressions_unique;
    $daily_stat[$i]['date'] = $result[$i]->date;
    $daily_stat[$i]['click'] = $result[$i]->clicks;
    $daily_stat[$i]['unique_clicks'] = $result[$i]->clicks_unique;
    $daily_stat[$i]['impressions'] = $result[$i]->impressions;
    $daily_stat[$i]['unique_impressions'] = $result[$i]->impressions_unique;
  }
  
  $stat = array();
  array_push($stat, $total_data, $daily_stat);
  dpm($stat);
  $markup = theme('simpleads_statsprint', array($stat));
  return $markup;
}