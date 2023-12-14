class CreateDriver < ActiveRecord::Migration[7.1]
  def change
    create_table :drivers do |t|
      t.string :driver_first_name
      t.string :driver_last_name
      t.string :driver_identification_number
      t.string :driver_email
      t.string :telephone_number

      t.datetime :birthdate

      t.timestamps
    end
    add_index :driver, :telephone_number, unique: true
  end
end
