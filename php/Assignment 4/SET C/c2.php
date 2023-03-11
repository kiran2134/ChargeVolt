<html>

<body>
    <?php
    interface PropertyInterface
    {
        public function setProperty($name, $value);
        public function getProperty($name);
    }

    interface HomeInterface
    {
        public function setHasApartment($bool);
        public function getHasSociety(): bool;
    }

    class Bungalow implements PropertyInterface, HomeInterface
    {
        private $properties = [];
        private $hasGarden = false;

        public function setProperty($name, $value)
        {
            $this->properties[$name] = $value;
        }

        public function getProperty($name)
        {
            return isset($this->properties[$name]) ? $this->properties[$name] : null;
        }

        public function setHasApartment($bool)
        {
            // No-op: Bungalow does not have an apartment
        }

        public function getHasSociety(): bool
        {
            return false;
        }

        public function setHasGarden($bool)
        {
            $this->hasGarden = $bool;
        }

        public function getHasGarden(): bool
        {
            return $this->hasGarden;
        }
    }
    $bungalow = new Bungalow();
    $bungalow->setProperty('location', 'beachside');
    $bungalow->setProperty('size', 2000);
    $bungalow->setHasGarden(true);

    echo "Location: " . $bungalow->getProperty('location') . "\n";
    echo "Size: " . $bungalow->getProperty('size') . "\n";
    echo "Has Garden: " . ($bungalow->getHasGarden() ? "Yes" : "No") . "\n";
    //echo "Has Apartment: " . ($bungalow->getHasApartment() ? "Yes" : "No") . "\n";
    echo "Has Society: " . ($bungalow->getHasSociety() ? "Yes" : "No") . "\n";
    ?>
</body>

</html>