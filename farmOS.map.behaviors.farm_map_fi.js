(function () {
  farmOS.map.behaviors.farm_map_fi = {
    attach: function (instance) {

      // Add Taustakartta layer.
      var opts1 = {
        title: 'Taustakartta',
        url: 'http://tiles.kartat.kapsi.fi/taustakartta/{z}/{x}/{y}.jpg',
        group: 'Base layers',
      };
      instance.addLayer('xyz', opts1);

      // Add Ortokuva layer.
      var opts2 = {
        title: 'Ortokuva',
        url: 'http://tiles.kartat.kapsi.fi/ortokuva/{z}/{x}/{y}.jpg',
        group: 'Base layers',
      };
      instance.addLayer('xyz', opts2);
    },
  };
}());
