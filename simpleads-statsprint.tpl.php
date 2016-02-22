<?php
$index = count($data[1]);
dpm(data[0]);
dpm(data[1]);
?>
<h2>Total</h2>
<table>
			<tr>
				<th>Clicks</th>
				<th>Unique clicks</th>
				<th>Impressions</th>
				<th>Unique impressions</th>
				<th>Click-through rate</th>
			</tr>
			<tr>
				<td><?php print $data[0]['click']; ?></td>
				<td><?php print $data[0]['unique_clicks']; ?></td>
				<td><?php print $data[0]['impressions']; ?></td>
				<td><?php print $data[0]['unique_impressions']; ?></td>
				<td><?php print 
            ($data[0]['unique_clicks']/$data[0]['unique_impressions']) * 100;
          ?></td>
			</tr>							
	</table>
<h2>Daily statistics</h2>
<table>
  <tr>
    <th>Date</th>
    <th>Clicks</th>
    <th>Unique Clicks</th>
    <th>Impressions</th>
    <th>Unique Impressions</th>
  </tr>
  <?php for ($i = 0; $i < $index; $i++): ?>
    <tr>
      <td>
        <?php print date('d/m/y H:i A', $data[1][$i]['date']); ?>
      </td>
      <td>
        <?php print $data[1][$i]['click']; ?>
      </td>
      <td>
        <?php print $data[1][$i]['unique_clicks']; ?>
      </td>
      <td>
        <?php print $data[1][$i]['impressions']; ?>
      </td>
      <td>
        <?php print $data[1][$i]['unique_impressions']; ?>
      </td>
    </tr>
  <?php endfor; ?>
</table>