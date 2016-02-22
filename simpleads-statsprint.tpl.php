<?php
$index = count($data[1]);
?>
<h1 style="text-align: center">SimpleAds Statistics</h1>
<h2>Total</h2>
<table style="border-collapse: collapse; width: 100%;">
			<tr>
				<th style="text-align: left; padding: 8px; background-color: #E1E2DC; color: #000;">Clicks</th>
				<th style="text-align: left; padding: 8px; background-color: #E1E2DC; color: #000;">Unique clicks</th>
				<th style="text-align: left; padding: 8px; background-color: #E1E2DC; color: #000;">Impressions</th>
				<th style="text-align: left; padding: 8px; background-color: #E1E2DC; color: #000;">Unique impressions</th>
				<th style="text-align: left; padding: 8px; background-color: #E1E2DC; color: #000;">Click-through rate</th>
			</tr>
			<tr>
				<td style="text-align: left; padding: 8px;"><?php print $data[0]['click']; ?></td>
				<td style="text-align: left; padding: 8px;"><?php print $data[0]['unique_clicks']; ?></td>
				<td style="text-align: left; padding: 8px;"><?php print $data[0]['impressions']; ?></td>
				<td style="text-align: left; padding: 8px;"><?php print $data[0]['unique_impressions']; ?></td>
				<td style="text-align: left; padding: 8px;"><?php print 
            round(
                (($data[0]['unique_clicks']/$data[0]['unique_impressions']) * 100), 4) . '%' ;
          ?></td>
			</tr>							
	</table>
<h2>Daily statistics</h2>
<table style="border-collapse: collapse; width: 100%;">
  <tr>
    <th style="text-align: left; padding: 8px; background-color: #E1E2DC; color: #000;">Date</th>
    <th style="text-align: left; padding: 8px; background-color: #E1E2DC; color: #000;">Clicks</th>
    <th style="text-align: left; padding: 8px; background-color: #E1E2DC; color: #000;">Unique Clicks</th>
    <th style="text-align: left; padding: 8px; background-color: #E1E2DC; color: #000;">Impressions</th>
    <th style="text-align: left; padding: 8px; background-color: #E1E2DC; color: #000;">Unique Impressions</th>
  </tr>
  <?php for ($i = 0; $i < $index; $i++): ?>
    <tr>
      <td style="text-align: left; padding: 8px;">
        <?php print date('d/m/y H:i A', $data[1][$i]['date']); ?>
      </td>
      <td style="text-align: left; padding: 8px;">
        <?php print $data[1][$i]['click']; ?>
      </td>
      <td style="text-align: left; padding: 8px;">
        <?php print $data[1][$i]['unique_clicks']; ?>
      </td>
      <td style="text-align: left; padding: 8px;">
        <?php print $data[1][$i]['impressions']; ?>
      </td>
      <td style="text-align: left; padding: 8px;">
        <?php print $data[1][$i]['unique_impressions']; ?>
      </td>
    </tr>
  <?php endfor; ?>
</table>